//
// Created by youba on 01/10/2023.
//

#include "ForwardParallax.hpp"

ForwardParallax::ForwardParallax(UnitiGameEngine::IObject &gameObject) : AScript(gameObject) { }

void ForwardParallax::start() { }

void ForwardParallax::update() {
    for (auto &object : this->_gameObject.getChildren()) {
        object->getTransform().position.x -= this->_speed * this->_deltaTime.getElapsedTime().asSeconds() * 100;
        if (object->getTransform().position.x < this->_end - this->_width) {
            float exceeded = (this->_end - this->_width) - object->getTransform().position.x;
            object->getTransform().position.x = this->_width + (this->_end - exceeded - 2);
        }
    }
    this->_deltaTime.restart();
}

void ForwardParallax::awake(const Json::Value &value) {
    this->_speed = value.get("speed", 0).asFloat();
    this->_width = value.get("width", 0).asFloat();
    this->_end = value.get("end", 0).asFloat();
}
