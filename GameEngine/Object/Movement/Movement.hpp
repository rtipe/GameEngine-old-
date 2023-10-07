//
// Created by youba on 05/10/2023.
//

#pragma once

#include "Vector2f.hpp"
#include "Clock.hpp"
#include "Vector3f.hpp"

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
        void setSpeed(float speed);
        void update();
        const Render::Clock &getClock() const;
        Render::Clock &getClock();
    private:
        Render::Vector3f getDeltaTime();
        std::mutex _mutex;
        Object &_object;
        float _speed = 0;
        Render::Vector2f _to;
        bool _isTo = false;
        Render::Clock _clock;
    };
}
