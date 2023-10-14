//
// Created by youba on 12/10/2023.
//

#include <iostream>
#include "Uniti.hpp"
#include "MissileHandler.hpp"
#include "Objects.hpp"

MissileHandler::MissileHandler(Uniti::Game::Object &gameObject) : AScript(gameObject) {}

void MissileHandler::start() {
    this->getEvent().addEvent("createMissile", [&] (const Json::Value &value) {
        for (const auto &data : value["data"]) {
            auto copy = Uniti::Game::Utils::Objects::find("exampleMissile");
            auto newMissile = std::make_unique<Uniti::Game::Object>(copy.value());
            newMissile->getTransform().getPosition().setX(data["position"]["x"].asFloat());
            newMissile->getTransform().getPosition().setY(data["position"]["y"].asFloat());
            newMissile->setName(data["name"].asString());
            this->getEvent().addEvent(data["name"].asString(), [&] (const Json::Value &value) {
                auto data = value["data"];
                auto exist = Uniti::Game::Utils::Objects::find(data["name"].asString(), this->getGameObject().getScene());
                if (exist) {
                    exist.value().get().getTransform().getPosition().setX(data["position"]["x"].asFloat());
                    exist.value().get().getTransform().getPosition().setY(data["position"]["y"].asFloat());
                }
            });
            this->getGameObject().getScene().getObjects().add(std::move(newMissile));
        }
    });
    this->getEvent().addEvent("destroyMissile", [&] (const Json::Value &value) {
        for (const auto &name : value["data"]) {
            auto exist = Uniti::Game::Utils::Objects::find(name.asString(), this->getGameObject().getScene());
            if (exist)
                this->getGameObject().getScene().getObjects().remove(name.asString());
        }
    });
}

void MissileHandler::update() {

}

void MissileHandler::awake(const Json::Value &value) {

}
