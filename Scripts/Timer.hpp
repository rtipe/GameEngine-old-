//
// Created by youba on 13/10/2023.
//

#pragma once

#include "AScript.hpp"

class Timer : public Uniti::Game::AScript {
public:
    explicit Timer(Uniti::Game::Object &gameObject);
    void start() override;
    void update() override;
    void awake(const Json::Value &value) override;
private:
    Uniti::Render::Clock _clock;
};
