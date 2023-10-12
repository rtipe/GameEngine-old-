//
// Created by Vincent Ballandi on 12/10/2023.
//

#pragma once

#include "AScript.hpp"

class LiveScript : public Uniti::Game::AScript {
public:
    explicit LiveScript(Uniti::Game::Object &gameObject);
    void start() override;
    void update() override;
    void awake(const Json::Value &value) override;
private:
    float _life = 0;
};
