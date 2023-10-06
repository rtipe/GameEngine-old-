//
// Created by youba on 05/10/2023.
//

#pragma once

#include <string>
#include <functional>
#include <map>
#include <mutex>
#include "IScript.hpp"

namespace Uniti::Game {
    using eventFunction = std::function<void()>;
    class Event {
    public:
        std::size_t addEvent(const std::string &name, eventFunction function);
        void removeEvent(const std::string &name);
        template<typename... Args>
        void emitEvent(const std::string &name, Args... args);
    private:
        std::map<std::string, std::vector<eventFunction>> _events;
        std::mutex _mutex;
    };
}