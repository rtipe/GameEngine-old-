#define IndentWidth 4
//
// Created by youba on 08/10/2023.
//

#include "Network.hpp"

#include <json/json.h>

#include <iostream>
#include <thread>

namespace Uniti::Game {
Network::Network(unsigned int port, unsigned int latence)
    : _socketUDP(this->_ioService, boost::asio::ip::udp::endpoint(
                                       boost::asio::ip::udp::v4(), port)),
      _latence(latence), _port(port), _queue(10000) {}

Network::~Network() {
  this->_ioService.stop();
  if (this->_ioThread.joinable())
    this->_ioThread.join();
}

void Network::start() {
  this->startReceive();
  this->_ioThread =
      std::thread([](boost::asio::io_context &io_context) { io_context.run(); },
                  std::ref(this->_ioService));
}

void Network::update() {
  this->sendPackets();
  this->handlePackets();
  for (const auto &server : this->_servers)
    server.second->updateEvent();
}

void Network::addServer(const std::string &name, const std::string &ip,
                        unsigned int port, const Json::Value &user) {
  this->_servers[name] = std::make_unique<Server>(ip, port, user);
}

void Network::removeServer(const std::string &name) {
  this->_servers.erase(name);
}

const Server &Network::getServer(const std::string &name) const {
  return *this->_servers.at(name);
}

Server &Network::getServer(const std::string &name) {
  return *this->_servers[name];
}

void Network::startReceive() {
  this->_socketUDP.async_receive_from(
      boost::asio::buffer(this->_buffer, this->_size), _senderEndPoint,
      [&](const boost::system::error_code &error, std::size_t length) {
        if (!error) {
          std::string text(this->_buffer, length);
          // std::cout << text << std::endl;
          memset(this->_buffer, 0, this->_size);
          auto *packet =
              new std::tuple<boost::asio::ip::udp::endpoint, std::string>(
                  _senderEndPoint, text);
          this->_queue.push(packet);
        } else {
          std::cerr << "Error : " << error.message() << std::endl;
        }
        this->startReceive();
      });
}

void Network::sendPackets() {
  if (this->_clock.getMilliSeconds() < this->_latence)
    return;
  this->_clock.restart();
  auto packets = this->getPacketToSend();
  for (auto &pair : packets) {
    try {
      Json::FastWriter fastWriter;
      std::string output = fastWriter.write(pair.second);
      this->_socketUDP.send_to(boost::asio::buffer(output), pair.first);
    } catch (std::exception &e) {
      std::cout << "error sent " << e.what() << std::endl;
    }
  }
}

void Network::receiveBuffer(const std::string &buffer,
                            boost::asio::ip::udp::endpoint &senderEndPoint) {
  auto it = std::find_if(
      this->_servers.begin(), this->_servers.end(), [&](const auto &server) {
        return senderEndPoint == server.second->getEndPoint();
      });
  if (it == this->_servers.end())
    return;
  try {
    Json::Value command;
    std::istringstream(buffer) >> command;
    Json::Value receivedInfo = command["received"];

    it->second->addPacket(command);
    it->second->checkSentPacket(receivedInfo);
  } catch (std::exception &e) {
    std::cout << "error inside receiveBuffer" << std::endl;
    std::cout << e.what() << std::endl;
  }
}

void Network::handlePackets() {
  this->_queue.consume_all(
      [&](std::tuple<boost::asio::ip::udp::endpoint, std::string> *packet) {
        this->receiveBuffer(std::get<1>(*packet), std::get<0>(*packet));
        delete packet;
      });
}

std::map<boost::asio::ip::udp::endpoint, Json::Value>
Network::getPacketToSend() {
  std::map<boost::asio::ip::udp::endpoint, Json::Value> packets;

  for (auto &server : this->_servers) {
    auto userPackets = server.second->getPacketToSend();
    for (const auto &userPacket : userPackets) {
      packets[server.second->getEndPoint()] = userPacket;
    }
  }
  return packets;
}
} // namespace Uniti::Game