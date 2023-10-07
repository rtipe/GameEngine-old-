//
// Created by youba on 05/10/2023.
//

#pragma once

#include <json/value.h>
#include "Box.hpp"

namespace Uniti::Game {
    class Object;
    class Collision {
    public:
        Collision();
        Collision(const Json::Value &value);
        Collision(const std::vector<Render::Box> &collisions);
        Collision(const Render::Box &box);
        void addBox(const Render::Box &box);
        const std::vector<Render::Box> &getBox() const;
        std::vector<Render::Box> &getBox();
        bool isInside(const Render::Vector2f &point) const;
        bool isInside(const Render::Box &box) const;
        bool isInside(const Object &object) const;
        bool isOverlap() const;
        void setOverlap(bool isOverlap);
    private:
        std::vector<Render::Box> _collisions;
        std::mutex _mutex;
        bool _isOverlap;
    };
}