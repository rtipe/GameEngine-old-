//
// Created by youba on 08/10/2023.
//

#pragma once

#include "AScript.hpp"

class NetworkBase : public Uniti::Game::AScript {
public:
    explicit NetworkBase(Uniti::Game::Object &gameObject);
    void start() override;
    void update() override;
    void awake(const Json::Value &value) override;
private:
};
