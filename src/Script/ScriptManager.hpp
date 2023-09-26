//
// Created by youba on 25/09/2023.
//

#pragma once

#include <string>
#include <memory>
#include <map>
#include "IScript.hpp"

namespace UnitiGameEngine {
    class ScriptManager {
        public:
            void addScript(std::unique_ptr<IScript> script, const std::string &name);
            bool removeScript(const std::string &name);
            IScript &getScript(const std::string &name);
            void update();
            void start();
        private:
            std::map<std::string, std::unique_ptr<IScript>> _scripts;
    };
}
