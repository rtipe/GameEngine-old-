//
// Created by youba on 12/10/2023.
//

#pragma once


#include "AScript.hpp"

class Animation : public Uniti::Game::AScript {
public:
    struct AnimationFrames {
        AnimationFrames() = default;
        AnimationFrames(const Json::Value &value);
        std::vector<Uniti::Render::Box> frames;
        float secondRemaining = 0;
    };
    explicit Animation(Uniti::Game::Object &gameObject);
    void start() override;
    void update() override;
    void awake(const Json::Value &value) override;
private:
    std::map<std::string, AnimationFrames> _animations;
    std::string _actualAnimation = "idle";
    int _iteration = 0;
    int _remaining = -1;
    Uniti::Render::Clock _clock;
};
