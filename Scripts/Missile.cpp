//
// Created by youba on 12/10/2023.
//

#include <iostream>
#include "Missile.hpp"
#include "Uniti.hpp"
#include "Objects.hpp"

Missile::Missile(Uniti::Game::Object &gameObject) : AScript(gameObject) {}

int Missile::_count = 0;

void Missile::start() {
    Missile::_count = (Missile::_count > 10000) ? 0 : Missile::_count + 1;
    this->_i = Missile::_count;
}

void Missile::update() {
    if (!this->_renamed) {
        this->getGameObject().setName(this->getGameObject().getName() + std::to_string(this->_i));
        this->_renamed = true;
    }
    if (this->getGameObject().getTransform().getPosition().getX() < -100 || this->getGameObject().getTransform().getPosition().getX() > 1920 ||
    this->getGameObject().getTransform().getPosition().getY() < -100 || this->getGameObject().getTransform().getPosition().getX() > 1080) {
        this->getGameObject().getScene().getObjects().remove(this->getGameObject().getName());
        return;
    }
    this->getGameObject().getMovement().move(this->_direction, this->_speed);
}

void Missile::awake(const Json::Value &value) {
    this->_direction = value["direction"];
    this->_speed = value.get("speed", 150).asFloat();
    this->_damage = value.get("damage", 10).asFloat();
}
