//
// Created by youba on 05/10/2023.
//

#include "Event.hpp"


namespace Uniti::Game {
    std::size_t Event::addEvent(const std::string &name, eventFunction function) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        if (!this->_events.contains(name))
            this->_events[name] = std::vector<eventFunction>();
        this->_events[name].push_back(function);
        return this->_events[name].size() - 1;
    }

    void Event::removeEvent(const std::string &name) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_events.erase(name);
    }

    void Event::removeEvent(const std::string &name, std::size_t id) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_events[name].erase(this->_events[name].begin() + id);
    }

    void Event::emitEvent(const std::string &name, const Json::Value &value) {
        auto it = _events.find(name);
        if (it != _events.end()) {
            for (auto &function : it->second) {
                function(value);
            }
        }
    }
}