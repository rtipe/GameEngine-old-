//
// Created by youba on 13/10/2023.
//

#include <iostream>
#include "DisplayHP.hpp"
#include "Text.hpp"

DisplayHP::DisplayHP(Uniti::Game::Object &gameObject) : AScript(gameObject) {}

void DisplayHP::start() {
    this->getEvent().addEvent("Vessel", [&] (const Json::Value &value) {
        for (const auto &nameVessel : value["data"].getMemberNames()) {
            if (nameVessel != "test") continue; // TODO: remplacer "test" par le pseudo plus tard
            auto data = value["data"][nameVessel];

            this->_life = data["life"].asFloat();
        }
    });
    this->getEvent().addEvent("destroyEntity", [&] (const Json::Value &value) {
        for (const auto &name : value["data"]) {
            if (name != "test") continue;
            this->_life = 0;
        }
    });
}

void DisplayHP::update() {
    if (!this->getGameObject().hasPrintable() || this->getGameObject().getPrintable().getTypeName() != "text") return;
    Uniti::Render::Text &text = dynamic_cast<Uniti::Render::Text &>(this->getGameObject().getPrintable());

    text.setString(std::to_string(this->_life) + " HP");
}

void DisplayHP::awake(const Json::Value &value) {

}
