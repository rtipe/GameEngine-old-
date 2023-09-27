//
// Created by youba on 25/09/2023.
//

#include <algorithm>
#include "ScriptManager.hpp"

namespace UnitiGameEngine {

    void ScriptManager::addScript(std::unique_ptr<IScript> script, const std::string &name) {
        this->_scripts[name] = std::move(script);
    }

    bool ScriptManager::removeScript(const std::string &name) {
        return this->_scripts.erase(name);
    }

    IScript &ScriptManager::getScript(const std::string &name) {
        return this->_scripts.at(name).operator*();
    }

    void ScriptManager::update() {
        for (auto &script : this->_scripts) {
            script.second->update();
        }
    }

    void ScriptManager::start() {
        for (auto &script : this->_scripts) {
            script.second->start();
        }
    }
}
