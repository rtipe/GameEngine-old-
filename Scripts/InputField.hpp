//
// Created by azerlus on 12/10/2023.
//

#pragma once

#include "AScript.hpp"

class InputField : public Uniti::Game::AScript {
    public:
        explicit InputField(Uniti::Game::Object &gameObject);
        void start() override;
        void update() override;
        void awake(const Json::Value &value) override;
        void checkActive();
        void writeInputField();
        static std::string _username;
private:
    float _width;
        float _height;
        bool _active;
        int _maxChar;
};
