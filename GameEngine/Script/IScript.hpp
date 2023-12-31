//
// Created by youba on 05/10/2023.
//

#pragma once

#include <json/value.h>
#include "Event.hpp"
#include "Clock.hpp"

namespace Uniti::Game {
    class Object;
    class IScript {
    public:
        virtual ~IScript() = default;
        virtual void start() = 0;
        virtual void update() = 0;
        virtual void awake(const Json::Value &value) = 0;
        virtual const Object &getGameObject() const = 0;
        virtual Object &getGameObject() = 0;
        virtual const Event &getEvent() const = 0;
        virtual Event &getEvent() = 0;
        virtual const Render::Clock &getClock() const = 0;
        virtual Render::Clock &getClock() = 0;
    };
}