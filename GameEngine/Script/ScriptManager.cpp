//
// Created by youba on 05/10/2023.
//

#include "ScriptManager.hpp"
#include "Uniti.hpp"

namespace Uniti::Game {
    ScriptManager::ScriptManager(const Json::Value &value, Object &object): _data(value) {
        for (const auto &script: value) {
            auto name = script["name"].asString();
            this->addScript(Uniti::Game::Core::getScriptFactory().createScript(name, object), name);
            this->getScript(name).awake(script);
        }
        this->start();
    }

    void ScriptManager::addScript(std::unique_ptr<IScript> script, const std::string &name) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_scripts[name] = std::move(script);
    }

    bool ScriptManager::removeScript(const std::string &name) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        return this->_scripts.erase(name);
    }

    IScript &ScriptManager::getScript(const std::string &name) {
        return *this->_scripts.at(name);
    }

    bool ScriptManager::contentScript(const std::string &name) const {
        return this->_scripts.contains(name);
    }

    void ScriptManager::update() {
        for (const auto &script : this->_scripts) {
            script.second->getClock().restart();
            script.second->update();
        }
    }

    void ScriptManager::start() {
        for (const auto &script : this->_scripts) {
            script.second->start();
        }
    }

    const Json::Value &ScriptManager::getData() const {
        return this->_data;
    }

    template<typename... Args>
    void ScriptManager::emitEvent(const std::string &name, Args... args) {
        for (const auto &script : this->_scripts) {
            script.second->getEvent().emitEvent(name, args...);
        }
    }
}