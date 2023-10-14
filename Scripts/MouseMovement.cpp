//
// Created by youba on 08/10/2023.
//

#include <iostream>
#include "Uniti.hpp"
#include "Mouse.hpp"
#include "Input.hpp"
#include "MouseMovement.hpp"
#include "Objects.hpp"
#include "Explosion.hpp"

MouseMovement::MouseMovement(Uniti::Game::Object &gameObject) : AScript(gameObject) { }

void MouseMovement::start() {
    this->getEvent().addEvent("Vessel", [&] (const Json::Value &value) {
        for (const auto &nameVessel : value["data"].getMemberNames()) {
            auto data = value["data"][nameVessel];
            auto position = Uniti::Render::Vector2f(data["position"]);
            auto id = data["id"].asString();
            std::vector<std::string> vesselType = {"BasicEnemy", "Kamikaze", "Sniper", "Tank", "Boss"};
            std::string vesselName = "BasicVessel";

            auto it = std::find_if(vesselType.begin(), vesselType.end(), [&] (const std::string &type) {
                return id.starts_with(type);
            });
            if (it != vesselType.end()) vesselName = *it;

            auto copy = Uniti::Game::Utils::Objects::find(vesselName);
            auto vessel = Uniti::Game::Utils::Objects::find(id);

            if (copy == std::nullopt) return;
            if (vessel == std::nullopt) {
                auto newVessel = std::make_unique<Uniti::Game::Object>(copy.value());
                newVessel->getTransform().getPosition().setX(position.getX());
                newVessel->getTransform().getPosition().setY(position.getY());
                newVessel->setName(id);
                this->getGameObject().getScene().getObjects().add(std::move(newVessel));
            } else {
                if (position.getX() != vessel.value().get().getTransform().getPosition().getX() ||
                    position.getY() != vessel.value().get().getTransform().getPosition().getY()) {
                    vessel.value().get().getTransform().getPosition().setX(position.getX());
                    vessel.value().get().getTransform().getPosition().setY(position.getY());
                }
            }
        }
    });
    this->getEvent().addEvent("destroyEntity", [&] (const Json::Value &value) {
        for (const auto &name : value["data"]) {
            this->getGameObject().getScene().getObjects().remove(name.asString());
            auto vessel = Uniti::Game::Utils::Objects::find(name.asString());
            std::vector<std::string> noExplosion = {"VesselHeal", "VesselWeapon"};

            auto it = std::find_if(noExplosion.begin(), noExplosion.end(), [&] (const std::string &type) {
                return name.asString().starts_with(type);
            });
            if (it != noExplosion.end()) continue;
            Explosion::createExplosion({
                vessel.value().get().getTransform().getPosition().getX(),
                vessel.value().get().getTransform().getPosition().getY(),
            });
        }
    });
}

void MouseMovement::update() {
    if (Uniti::Render::Mouse::isMousePressed(Uniti::Render::Mouse::KeyMouse::LEFT)) {
        Uniti::Game::Core::getNetwork().getServer("game").sendEvent("vesselShoot", {});
    }
    Json::Value position;

    if (!isPressed) {
        if (Uniti::Render::Input::isPressed(Uniti::Render::Input::Left)) {
            _normal = {-1, 0};
            isPressed = true;
        }
        if (Uniti::Render::Input::isPressed(Uniti::Render::Input::Right)) {
            _normal = {1, 0};
            isPressed = true;
        }
        if (Uniti::Render::Input::isPressed(Uniti::Render::Input::Up)) {
            _normal = {0, -1};
            isPressed = true;
        }
        if (Uniti::Render::Input::isPressed(Uniti::Render::Input::Down)) {
            _normal = {0, 1};
            isPressed = true;
        }
    } else {
        if (
            Uniti::Render::Input::isReleased(Uniti::Render::Input::Down) ||
            Uniti::Render::Input::isReleased(Uniti::Render::Input::Up) ||
            Uniti::Render::Input::isReleased(Uniti::Render::Input::Right) ||
            Uniti::Render::Input::isReleased(Uniti::Render::Input::Left)
        ) {
            isPressed = false;
            _normal = {0, 0};
        }
    }
    position["x"] = _normal.getX();
    position["y"] = _normal.getY();
    Uniti::Game::Core::getNetwork().getServer("game").sendEvent("vesselMovement", position);
}

void MouseMovement::awake(const Json::Value &value) {
    this->_speed = value.get("speed", 5).asFloat();
}
