//
// Created by youba on 05/10/2023.
//

#pragma once

#include "Vector2f.hpp"

namespace Uniti::Game {
    class Object;
    class Movement {
    public:
        Movement(Object &object);
        void moveTo(const Render::Vector2f &position, float speed);
        void moveForward(float speed);
        void moveBackward(float speed);
        void moveLeft(float speed);
        void moveRight(float speed);
        void move(const Render::Vector2f &normal, float speed);
        void cancelMovement();
        bool isMoving() const;
        float getSpeed() const;
        void setSpeed();
        void update();
    private:
        std::mutex _mutex;
        Object &_object;
        float _speed;
        Render::Vector2f &_to;
        bool isTo;
    };
}
