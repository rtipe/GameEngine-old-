//
// Created by youba on 08/10/2023.
//

#pragma once


#include <boost/asio.hpp>
#include "Server.hpp"

namespace Uniti::Game {
    class Network {
    public:
        Network(unsigned int port, unsigned int latence);
        void start();
        void addServer(const std::string &name, const std::string &ip, unsigned int port, const Json::Value &user);
        void removeServer(const std::string &name);
        const Server &getServer(const std::string &name) const;
        Server &getServer(const std::string &name);
    private:
        std::map<boost::asio::ip::udp::endpoint, Json::Value> getPacketToSend();
        void startReceive();
        void sendPackets();
        void receiveBuffer(const std::string &buffer, boost::asio::ip::udp::endpoint &senderEndPoint, const boost::system::error_code &error, std::size_t length);
        std::map<std::string, std::unique_ptr<Server>> _servers;
        boost::asio::io_service _ioService;
        boost::asio::ip::udp::socket _socketUDP;
        std::mutex _mutex;
        unsigned int _latence;
        unsigned int _port;
    };
}
