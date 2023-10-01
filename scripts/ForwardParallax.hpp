//
// Created by youba on 01/10/2023.
//

#pragma once

#include "../src/Script/AScript.hpp"

class ForwardParallax: public UnitiGameEngine::AScript {
public:
    explicit ForwardParallax(UnitiGameEngine::IObject &gameObject);
    void start() override;
    void update() override;
    void awake(const Json::Value &value) override;
private:
    float _speed = 0;
    float _width = 0;
    float _end = 0;
    sf::Clock _deltaTime;
};