//
// Created by youba on 14/10/2023.
//

#pragma once


#include "AScript.hpp"

class Explosion : public Uniti::Game::AScript {
public:
    static void createExplosion(const Uniti::Render::Vector2f &position);
    explicit Explosion(Uniti::Game::Object &gameObject);
    void start() override;
    void update() override;
    void awake(const Json::Value &value) override;
private:
    static int _count;
    Uniti::Render::Clock _clock;
};
