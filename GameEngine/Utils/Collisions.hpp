//
// Created by youba on 07/10/2023.
//

#pragma once

#include <optional>
#include "Vector2f.hpp"
#include "Vector3f.hpp"
#include "Box.hpp"
#include "Object.hpp"

namespace Uniti::Game::Utils {
    class Collisions {
    public:
        static std::optional<std::reference_wrapper<Object>> isCollided(const Render::Vector2f &position);
        static std::optional<std::reference_wrapper<Object>> isCollided(const Render::Vector3f &position);
        static std::optional<std::reference_wrapper<Object>> isCollided(const Render::Box &position);
        static std::optional<std::reference_wrapper<Object>> isCollided(const Object &position);
        static std::optional<std::reference_wrapper<Object>> isOverlapped(const Render::Vector2f &position);
        static std::optional<std::reference_wrapper<Object>> isOverlapped(const Render::Vector3f &position);
        static std::optional<std::reference_wrapper<Object>> isOverlapped(const Render::Box &position);
        static std::optional<std::reference_wrapper<Object>> isOverlapped(const Object &position);
    };
}
