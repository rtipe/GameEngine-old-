//
// Created by youba on 08/10/2023.
//

#include <json/json.h>
#include <iostream>
#include "Network.hpp"

namespace Uniti::Game {
    Network::Network(unsigned int port, unsigned int latence):
    _socketUDP(this->_ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
    _latence(latence),
    _port(port) { }

    void Network::start() {
        this->startReceive();
        std::async(std::launch::async, [&]() {
           this->sendPackets();
        });
    }

    void Network::addServer(const std::string &name, const std::string &ip, unsigned int port , const Json::Value &user) {
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
        std::string buffer;
        boost::asio::ip::udp::endpoint senderEndPoint;
        this->_socketUDP.async_receive_from(boost::asio::buffer(buffer), senderEndPoint,
        [&] (const boost::system::error_code &error, std::size_t length) {
            this->receiveBuffer(buffer, senderEndPoint, error, length);
            this->startReceive();
        });
    }

    void Network::sendPackets() {
        auto packets = this->getPacketToSend();
        for (auto &pair : packets) {
            Json::FastWriter fastWriter;
            std::string output = fastWriter.write(pair.second);
            this->_socketUDP.send_to(boost::asio::buffer(output), pair.first);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(this->_latence));
        this->sendPackets();
    }

    void Network::receiveBuffer(const std::string &buffer, boost::asio::ip::udp::endpoint &senderEndPoint,
    const boost::system::error_code &error, std::size_t length) {
        auto it = std::find_if(this->_servers.begin(), this->_servers.end(), [&] (const auto &server) {
           return senderEndPoint == server.second->getEndPoint();
        });
        if (it == this->_servers.end()) return;
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

    std::map<boost::asio::ip::udp::endpoint, Json::Value> Network::getPacketToSend() {
        std::map<boost::asio::ip::udp::endpoint, Json::Value> packets;

        for (auto &server : this->_servers) {
            auto userPackets = server.second->getPacketToSend();
            for (const auto &userPacket : userPackets) {
                packets[server.second->getEndPoint()] = userPacket;
            }
        }
        return packets;
    }
}