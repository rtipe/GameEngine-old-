//
// Created by youba on 05/10/2023.
//

#pragma once

#include <string>
#include <functional>
#include <map>
#include <mutex>

namespace Uniti::Game {
    using eventFunction = std::function<void()>;
    class Event {
    public:
        std::size_t addEvent(const std::string &name, eventFunction function);
        void removeEvent(const std::string &name);
        void removeEvent(const std::string &name, std::size_t id);
        template<typename... Args>
        void emitEvent(const std::string &name, Args... args);
    private:
        std::map<std::string, std::vector<eventFunction>> _events;
        std::mutex _mutex;
    };
}