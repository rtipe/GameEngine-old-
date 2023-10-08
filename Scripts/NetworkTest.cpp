//
// Created by youba on 08/10/2023.
//

#include "NetworkTest.hpp"
#include "Uniti.hpp"

NetworkTest::NetworkTest(Uniti::Game::Object &gameObject) : AScript(gameObject) { }

void NetworkTest::start() {
    Uniti::Game::Core::getNetwork().addServer("test", "127.0.0.1", 7070, "test");
}

void NetworkTest::update() {

}

void NetworkTest::awake(const Json::Value &value) {

}
