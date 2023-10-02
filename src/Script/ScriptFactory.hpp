//
// Created by youba on 26/09/2023.
//

#pragma once

#include <functional>
#include <memory>
#include <map>
#include <json/value.h>
#include "IScript.hpp"
#include "../Object/IObject.hpp"

namespace UnitiGameEngine {
    template<typename... Args>
    using creatorFunction = std::function<std::unique_ptr<IScript>(IObject &object)>;
    class ScriptFactory {
        public:
            std::unique_ptr<IScript> createScript(const std::string &name, IObject &object);
            template<typename OBJECT>
            void addScript(const std::string &name) {
                this->creators[name] = [&](IObject &object) -> std::unique_ptr<IScript> {
                    return std::make_unique<OBJECT>(object);
                };
            }
        private:
            std::map<std::string, creatorFunction<>> creators;
    };
}

