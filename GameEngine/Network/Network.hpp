//
// Created by youba on 08/10/2023.
//

#pragma once

#include <boost/asio.hpp>
#include <boost/lockfree/queue.hpp>
#include "Server.hpp"
#include "Clock.hpp"

namespace Uniti::Game {
    class Network {
    public:
        Network(unsigned int port, unsigned int latence);
        ~Network();
        void start();
        void update();
        void addServer(const std::string &name, const std::string &ip, unsigned int port, const Json::Value &user);
        void removeServer(const std::string &name);
        const Server &getServer(const std::string &name) const;
        Server &getServer(const std::string &name);
        void sendPackets();
    private:
        std::map<boost::asio::ip::udp::endpoint, Json::Value> getPacketToSend();
        void startReceive();
        void receiveBuffer(const std::string &buffer, boost::asio::ip::udp::endpoint &senderEndPoint);
        void handlePackets();
        std::map<std::string, std::unique_ptr<Server>> _servers;
        boost::asio::io_service _ioService;
        boost::asio::ip::udp::socket _socketUDP;
        std::mutex _mutex;
        unsigned int _latence;
        unsigned int _port;
        std::thread _ioThread;
        Render::Clock _clock;
        int _size = 50000;
        char _buffer[50000];
        boost::asio::ip::udp::endpoint _senderEndPoint;
        boost::lockfree::queue<std::tuple<boost::asio::ip::udp::endpoint, std::string> *> _queue;
    };
}
