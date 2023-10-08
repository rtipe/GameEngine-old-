//
// Created by youba on 08/10/2023.
//

#pragma once

#include "AScript.hpp"

class NetworkTest : public Uniti::Game::AScript {
public:
    explicit NetworkTest(Uniti::Game::Object &gameObject);
    void start() override;
    void update() override;
    void awake(const Json::Value &value) override;
private:
};
