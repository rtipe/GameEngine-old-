//
// Created by youba on 08/10/2023.
//

#pragma once

#include <json/value.h>
#include <boost/asio/ip/udp.hpp>
#include <list>

namespace Uniti::Game {
    class Server {
    public:
        Server(const std::string &ip, unsigned int port, const Json::Value &user);
        void sendEvent(const std::string &name, const Json::Value &value);
        const boost::asio::ip::udp::endpoint &getEndPoint() const;
        boost::asio::ip::udp::endpoint &getEndPoint();
        void addPacket(const Json::Value &packet);
        void updateEvent();
        void checkSentPacket(const Json::Value &sended);
        std::vector<Json::Value> getPacketToSend();
    private:
        Json::Value createPacket();
        std::map<std::string, Json::Value> _events;
        boost::asio::ip::udp::endpoint _endpoint;
        std::vector<Json::Value> _packetToHandle;
        std::list<int> _packetHandled;
        std::vector<std::tuple<Json::Value, int>> _sentPacket;
        std::vector<Json::Value> _packetToSend;
        std::list<int> _receivedPacket;
        int _waitedId = 0;
        int _sendId = 0;
        std::mutex _mutex;
        Json::Value _user;
    };
}
