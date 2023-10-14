#define IndentWidth 4
//
// Created by youba on 12/10/2023.
//

#include "Animation.hpp"

#include <iostream>

#include "Mouse.hpp"
#include "Sprite.hpp"

Animation::Animation(Uniti::Game::Object &gameObject) : AScript(gameObject) {}

void Animation::start() {
  this->getEvent().addEvent("animation", [&](const Json::Value &value) {
    const std::string &animationName = value.get("name", "idle").asString();
    bool loop = value.get("loop", false).asBool();
    int iteration = value.get("iteration", 1).asInt();

    if (!this->_animations.contains(animationName))
      return;
    this->_actualAnimation = animationName;
    this->_remaining = iteration;
    if (loop)
      this->_remaining = -1;
    this->_iteration = 0;
  });
}

void Animation::update() {
  if (!this->_animations.contains(this->_actualAnimation))
    return;
  if (static_cast<float>(this->_clock.getMilliSeconds()) / 1000 <
      this->_animations[this->_actualAnimation].secondRemaining)
    return;

  Uniti::Render::Sprite &sprite = dynamic_cast<Uniti::Render::Sprite &>(
      this->getGameObject().getPrintable());
  this->_iteration++;
  if (this->_iteration >=
      this->_animations[this->_actualAnimation].frames.size()) {
    if (this->_remaining == 0) {
      this->_actualAnimation = "idle";
      this->_remaining = -1;
    } else if (this->_remaining > 0) {
      this->_remaining--;
    }
    this->_iteration = 0;
  }
  sprite.setTextureRect(
      this->_animations[this->_actualAnimation].frames[this->_iteration]);
  this->_clock.restart();
}

void Animation::awake(const Json::Value &value) {
  const Json::Value &animations = value["animations"];

  for (const auto &animation : animations) {
    const std::string &name = animation["name"].asString();
    this->_animations.emplace(name, AnimationFrames(animation));
  }
}

Animation::AnimationFrames::AnimationFrames(const Json::Value &value) {
  for (const auto &frame : value["frames"])
    this->frames.push_back(frame);
  this->secondRemaining = value.get("time", 0).asFloat();
}
