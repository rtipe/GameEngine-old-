//
// Created by youba on 08/10/2023.
//

#include <iostream>
#include "Uniti.hpp"
#include "Mouse.hpp"
#include "MouseMovement.hpp"

MouseMovement::MouseMovement(Uniti::Game::Object &gameObject) : AScript(gameObject) { }

void MouseMovement::start() {

}

void MouseMovement::update() {
    if (Uniti::Render::Mouse::isMousePressed(Uniti::Render::Mouse::KeyMouse::LEFT)) {
        this->getGameObject().getMovement().moveTo(
            Uniti::Render::Mouse::getPosition(Uniti::Game::Core::getWindow()),
            this->_speed
        );
    }
}

void MouseMovement::awake(const Json::Value &value) {
    this->_speed = value.get("speed", 0).asFloat();
}
