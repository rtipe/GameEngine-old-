//
// Created by youba on 08/10/2023.
//

#include <iostream>
#include "NetworkTest.hpp"
#include "Uniti.hpp"
#include "Objects.hpp"

NetworkTest::NetworkTest(Uniti::Game::Object &gameObject) : AScript(gameObject) { }

void NetworkTest::start() {
    Uniti::Game::Core::getNetwork().addServer("test", "127.0.0.1", 7070, "test");
    this->getEvent().addEvent("VesselPosition", [&] (const Json::Value &value) {
        auto data = value["data"];
        auto position = Uniti::Render::Vector2f(data["position"]);
        auto id = data["id"].asString();
        auto copy = Uniti::Game::Utils::Objects::find("second");
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
            position.getY() != vessel.value().get().getTransform().getPosition().getY())
                vessel.value().get().getMovement().moveTo(position, this->_speed);
        }
    });
}

void NetworkTest::update() {

}

void NetworkTest::awake(const Json::Value &value) {
    this->_speed = value.get("speed", 5).asFloat();
}
