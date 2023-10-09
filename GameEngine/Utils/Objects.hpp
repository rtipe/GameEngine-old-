//
// Created by youba on 05/10/2023.
//

#pragma once

#include <optional>
#include "Object.hpp"

namespace Uniti::Game::Utils {
    class Objects {
    public:
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const Scene &scene, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const ObjectManager &objectManager, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const Object &object, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find_if(std::function<bool(const Object &object)>, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find_if(const Scene &scene, std::function<bool(const Object &object)> function, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find_if(const ObjectManager &objectManager, std::function<bool(const Object &object)> function, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find_if(const Object &object, std::function<bool(const Object &object)> function, bool recursive = true);
    };
}
