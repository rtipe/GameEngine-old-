//
// Created by youba on 05/10/2023.
//

#pragma once

#include <string>
#include <functional>
#include <map>
#include <mutex>
#include <json/value.h>

namespace Uniti::Game {
    using eventFunction = std::function<void(const Json::Value &value)>;
    class Event {
    public:
        std::size_t addEvent(const std::string &name, eventFunction function);
        void removeEvent(const std::string &name);
        void removeEvent(const std::string &name, std::size_t id);
        void emitEvent(const std::string &name, const Json::Value &value);
    private:
        std::map<std::string, std::vector<eventFunction>> _events;
        std::mutex _mutex;
    };
}