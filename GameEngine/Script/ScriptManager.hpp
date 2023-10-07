//
// Created by youba on 05/10/2023.
//

#pragma once

#include <json/value.h>
#include "IScript.hpp"

namespace Uniti::Game {
    class Object;
    class ScriptManager {
    public:
        ScriptManager(const Json::Value &value, Object &object);
        void addScript(std::unique_ptr<IScript> script, const std::string &name);
        bool removeScript(const std::string &name);
        IScript &getScript(const std::string &name);
        bool contentScript(const std::string &name) const;
        void update();
        void start();
        void emitEvent(const std::string &name, const Json::Value &value);
        const Json::Value &getData() const;
    private:
        std::mutex _mutex;
        std::map<std::string, std::unique_ptr<IScript>> _scripts;
        Json::Value _data;
    };
}
