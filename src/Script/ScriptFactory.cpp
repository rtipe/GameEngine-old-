//
// Created by youba on 26/09/2023.
//

#include "ScriptFactory.hpp"

namespace UnitiGameEngine {

    std::unique_ptr<IScript>
    ScriptFactory::createScript(const std::string &name, Uniti &game, IObject &object) {
        auto it = this->creators.find(name);

        if (it == this->creators.end())
            throw std::invalid_argument("Invalid type");
        return it->second(game, object);
    }
}
