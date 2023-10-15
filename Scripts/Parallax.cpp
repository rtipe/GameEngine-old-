//
// Created by azerlus on 12/10/23.
//

#include "Parallax.hpp"
#include "Uniti.hpp"

Parallax::Parallax(Uniti::Game::Object &gameObject) : AScript(gameObject)
{
}

void Parallax::start()
{
}

void Parallax::update()
{
    for (auto &object : this->getGameObject().getChildren().getObjects()) {
        Uniti::Render::Vector2f normal(-1, 0);
        object->getMovement().move(normal, this->_speed);
        if (object->getTransform().getPosition().getX() < this->_end - this->_width) {
            float exceeded = (this->_end - this->_width) - object->getTransform().getPosition().getX();
            object->getTransform().getPosition().setX(this->_width + (this->_end - exceeded - 2));
        }
    }
}

void Parallax::awake(const Json::Value &value)
{
    this->_speed = value.get("speed", 0).asFloat();
    this->_width = value.get("width", 0).asFloat();
    this->_end   = value.get("end", 0).asFloat();
}
