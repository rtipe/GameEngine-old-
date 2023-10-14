//
// Created by youba on 12/10/2023.
//

#pragma once


#include "AScript.hpp"

class MissileHandler : public Uniti::Game::AScript {
public:
    explicit MissileHandler(Uniti::Game::Object &gameObject);
    void start() override;
    void update() override;
    void awake(const Json::Value &value) override;
};
