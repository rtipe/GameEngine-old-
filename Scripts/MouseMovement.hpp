//
// Created by youba on 08/10/2023.
//

#pragma once

#include "AScript.hpp"

class MouseMovement : public Uniti::Game::AScript {
public:
    explicit MouseMovement(Uniti::Game::Object &gameObject);
    void start() override;
    void update() override;
    void awake(const Json::Value &value) override;
private:
    float _speed = 0;
    Uniti::Render::Vector2f _normal;
    bool isPressed = false;
};
