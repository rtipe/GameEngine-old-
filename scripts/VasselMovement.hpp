//
// Created by youba on 30/09/2023.
//

#pragma once

#include "../src/Script/AScript.hpp"

class VasselMovement: public UnitiGameEngine::AScript {
    public:
        explicit VasselMovement(UnitiGameEngine::IObject &gameObject);
        void start() override;
        void update() override;
        void awake(const Json::Value &value) override;
    private:
        float _speed = 0;
        bool _isUp = false;
        bool _isDown = false;
        sf::Clock _deltaTime;
};

