//
// Created by youba on 30/09/2023.
//

#include <iostream>
#include "VasselMovement.hpp"

VasselMovement::VasselMovement(UnitiGameEngine::IObject &gameObject) : AScript(gameObject) {}

void VasselMovement::start() { }

void VasselMovement::update() {
    if (UnitiGameEngine::Uniti::getInstance().getInput().isPressed("Up")) {
        this->_isUp = true;
    }
    if (UnitiGameEngine::Uniti::getInstance().getInput().isPressed("Down")) {
        this->_isDown = true;
    }
    if (UnitiGameEngine::Uniti::getInstance().getInput().isReleased("Up")) {
        this->_isUp = false;
    }
    if (UnitiGameEngine::Uniti::getInstance().getInput().isReleased("Down")) {
        this->_isDown = false;
    }

    if (this->_isUp) {
        this->_gameObject.getTransform().position.y -= this->_speed * this->_deltaTime.getElapsedTime().asSeconds() * 100;
    } else if (this->_isDown) {
        this->_gameObject.getTransform().position.y += this->_speed * this->_deltaTime.getElapsedTime().asSeconds() * 100;
    }
    this->_deltaTime.restart();
}

void VasselMovement::awake(const Json::Value &value) {
    this->_speed = value.get("speed", 0).asFloat();
}
