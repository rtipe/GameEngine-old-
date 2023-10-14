//
// Created by youba on 12/10/2023.
//

#pragma once


#include "AScript.hpp"

class Missile : public Uniti::Game::AScript {
public:
    explicit Missile(Uniti::Game::Object &gameObject);
    void start() override;
    void update() override;
    void awake(const Json::Value &value) override;
private:
    Uniti::Render::Vector2f _direction;
    float _speed;
    float _damage;
    static int _count;
    int _i;
    bool _renamed = false;
};
