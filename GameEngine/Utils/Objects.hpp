//
// Created by youba on 05/10/2023.
//

#pragma once

#include "Object.hpp"

namespace Uniti::Game::Utils {
    class Objects {
        static Uniti::Game::Object &find(const std::string &name, bool recursive = true);
        static Uniti::Game::Object &find(const std::string &name, const Scene &scene, bool recursive = true);
        static Uniti::Game::Object &find(const std::string &name, const ObjectManager &objectManager, bool recursive = true);
        static Uniti::Game::Object &find(const std::string &name, const Object &object, bool recursive = true);
        static Uniti::Game::Object &find_if(std::function<bool(const Object &object)>, bool recursive = true);
        static Uniti::Game::Object &find_if(const Scene &scene, std::function<bool(const Object &object)> function, bool recursive = true);
        static Uniti::Game::Object &find_if(const ObjectManager &objectManager, std::function<bool(const Object &object)> function, bool recursive = true);
        static Uniti::Game::Object &find_if(const Object &object, std::function<bool(const Object &object)> function, bool recursive = true);
    };
}
