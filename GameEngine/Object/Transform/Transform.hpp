//
// Created by youba on 05/10/2023.
//

#pragma once


#include "Vector3f.hpp"
#include "Vector2f.hpp"

namespace Uniti::Game {
    class Transform {
    public:
        const Render::Vector3f &getPosition() const;
        Render::Vector3f &getPosition();
        const Render::Vector2f &getScale() const;
        Render::Vector2f &getScale();
        const Render::Vector2f &getOrigin() const;
        Render::Vector2f &getOrigin();
        float getRotation() const;
        void setRotation(float value);
    private:
        std::mutex _mutex;
        Render::Vector3f _position;
        Render::Vector2f _scale;
        Render::Vector2f _origin;
        float _rotation;
    };
}
