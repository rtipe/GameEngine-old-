//
// Created by youba on 05/10/2023.
//

#include "AScript.hpp"


namespace Uniti::Game {
    const Object &AScript::getGameObject() const {
        return this->_gameObject;
    }

    Object &AScript::getGameObject() {
        return this->_gameObject;
    }

    const Event &AScript::getEvent() const {
        return this->_event;
    }

    Event &AScript::getEvent() {
        return this->_event;
    }

    const Render::Clock &AScript::getClock() const {
        return this->_clock;
    }

    Render::Clock &AScript::getClock() {
        return this->_clock;
    }
}