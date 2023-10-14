//
// Created by azerlus on 12/10/23.
//

#pragma once

#include "AScript.hpp"

class Parallax : public Uniti::Game::AScript {
    public:
        explicit Parallax(Uniti::Game::Object &gameObject);
        void start() override;
        void update() override;
        void awake(const Json::Value &value) override;
    private:
        float _speed = 0;
        float _width = 0;
        float _end = 0;
};
