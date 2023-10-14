//
// Created by youba on 08/10/2023.
//

#include "Server.hpp"

#include <algorithm>

#include "Uniti.hpp"

namespace Uniti::Game {
Server::Server(const std::string &ip, unsigned int port,
               const Json::Value &user)
    : _endpoint(boost::asio::ip::address::from_string(ip), port), _user(user) {}

void Server::sendEvent(const std::string &name, const Json::Value &value) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_events[name] = value;
}

const boost::asio::ip::udp::endpoint &Server::getEndPoint() const {
  return this->_endpoint;
}

boost::asio::ip::udp::endpoint &Server::getEndPoint() {
  return this->_endpoint;
}

void Server::addPacket(const Json::Value &packet) {
  int id = packet.get("id", -1).asInt();

  if (id == -1) return;
  auto itToHandle =
      std::find_if(this->_packetToHandle.begin(), this->_packetToHandle.end(),
                   [&](const auto &value) {
                     int otherId = value.get("id", -1).asInt();
                     return id == otherId;
                   });
  if (itToHandle != this->_packetToHandle.end()) return;
  auto itHandled =
      std::find(this->_packetHandled.begin(), this->_packetHandled.end(), id);
  if (itHandled != this->_packetHandled.end()) return;
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_packetToHandle.push_back(packet);
}

void Server::updateEvent() {
  std::unique_lock<std::mutex> lock(this->_mutex);
  int nextId = (this->_waitedId + 1 >= 100) ? 0 : this->_waitedId + 1;

  auto itToHandle =
      std::find_if(this->_packetToHandle.begin(), this->_packetToHandle.end(),
                   [&](const auto &value) {
                     int id = value.get("id", -1).asInt();
                     return nextId == id;
                   });
  if (itToHandle == this->_packetToHandle.end()) return;
  Json::Value events = itToHandle.operator*()["events"];

  for (const auto &event : events) {
    const std::string &name = event.get("name", "undefined").asString();
    lock.unlock();
    Core::getSceneManager().getCurrentScene().getObjects().emitEvent(name,
                                                                     event);
    Core::getSceneManager().getGlobalScene().getObjects().emitEvent(name,
                                                                    event);
    lock.lock();
  }
  if (this->_packetHandled.size() > 16) this->_packetHandled.pop_front();
  this->_packetHandled.push_back(nextId);
  this->_packetToHandle.erase(itToHandle);
  this->_waitedId = nextId;
  lock.unlock();
  this->updateEvent();
}

void Server::checkSentPacket(const Json::Value &sent) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  std::erase_if(this->_sentPacket, [&](auto &packet) {
    Json::Value info = std::get<0>(packet);
    int id = info.get("id", -1).asInt();
    return std::any_of(sent.begin(), sent.end(), [&](const auto &sentId) {
      return sentId.asInt() == id;
    });
  });
  for (auto &packet : this->_sentPacket) {
    if (std::get<1>(packet) > 0)
      std::get<1>(packet) = std::get<1>(packet) - 1;
    else
      this->_packetToSend.push_back(std::get<0>(packet));
  }
  std::erase_if(this->_sentPacket,
                [&](auto &packet) { return std::get<1>(packet) <= 0; });
}

std::vector<Json::Value> Server::getPacketToSend() {
  std::vector<Json::Value> packets;

  packets.insert(packets.end(), this->_packetToSend.begin(),
                 this->_packetToSend.end());
  packets.push_back(createPacket());
  this->_packetToSend.clear();
  return packets;
}

Json::Value Server::createPacket() {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  Json::Value packet;
  Json::Value events;
  Json::Value received;
  Json::Value id = this->_sendId;
  int i = 0;

  this->_sendId = (this->_sendId + 1 < 100) ? this->_sendId + 1 : 0;
  for (const auto &eventRow : this->_events) {
    Json::Value event;
    event["name"] = eventRow.first;
    event["data"] = eventRow.second;
    events.insert(i, event);
    i++;
  }
  i = 0;
  for (const auto &idPacket : this->_receivedPacket) {
    received.insert(i, idPacket);
    i++;
  }
  this->_events.clear();
  this->_receivedPacket.clear();
  packet["events"] = events;
  packet["received"] = received;
  packet["id"] = id;
  packet["user"] = this->_user;
  return packet;
}
}  // namespace Uniti::Game