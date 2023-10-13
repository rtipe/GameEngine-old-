//
// Created by youba on 05/10/2023.
//

#pragma once

#include <json/value.h>
#include "Box.hpp"
#include "Transform.hpp"

namespace Uniti::Game {
    class Object;
    class Collision {
    public:
        Collision(Transform &transform);
        Collision(const Json::Value &value, Transform &transform);
        Collision(const std::vector<Render::Box> &collisions, Transform &transform);
        Collision(const Render::Box &box, Transform &transform);
        void addBox(const Render::Box &box);
        const std::vector<Render::Box> &getBox() const;
        std::vector<Render::Box> &getBox();
        bool isInside(const Render::Vector2f &point) const;
        bool isInside(const Render::Box &box, const Render::Vector3f &position) const;
        bool isInside(const Object &object) const;
        bool isOverlap() const;
        void setOverlap(bool isOverlap);
    private:
        std::vector<Render::Box> _collisions;
        std::mutex _mutex;
        Transform &_transform;
        bool _isOverlap = false;
    };
}