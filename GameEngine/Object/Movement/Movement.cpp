#define IndentWidth 4
//
// Created by youba on 05/10/2023.
//

#include "Movement.hpp"

#include <iostream>

#include "Collisions.hpp"
#include "Object.hpp"
#include "Vector.hpp"

namespace Uniti::Game {
Movement::Movement(Object &object) : _object(object) {}

void Movement::moveTo(const Render::Vector2f &position, float speed) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_to = position;
  this->_speed = speed;
  this->_isTo = true;
}

void Movement::moveForward(float speed) { this->move({0, -1}, speed); }

void Movement::moveBackward(float speed) { this->move({0, 1}, speed); }

void Movement::moveLeft(float speed) { this->move({-1, 0}, speed); }

void Movement::moveRight(float speed) { this->move({1, 0}, speed); }

void Movement::move(const Render::Vector2f &normal, float speed) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_isTo = false;
  Render::Vector3f position(this->_object.getTransform().getPosition());
  Render::Vector3f normal3f(normal.getX(), normal.getY(), 0);
  Render::Vector3f speed3f(speed, speed, speed);
  Render::Vector3f newPosition = position + normal3f * speed3f * getDeltaTime();
  this->_object.getTransform().getPosition().setX(newPosition.getX());
  this->_object.getTransform().getPosition().setY(newPosition.getY());
  std::optional<std::reference_wrapper<Object>> isCollided =
      Utils::Collisions::isCollided(this->_object);
  std::optional<std::reference_wrapper<Object>> isOverlapped =
      Utils::Collisions::isOverlapped(this->_object);
  if (isCollided && !this->_object.getCollision().isOverlap()) {
    isCollided.value().get().getScriptManager().emitEvent(
        "collided", this->_object.getName());
    this->_object.getTransform().getPosition().operator=(position);
  }
  if (isOverlapped)
    isOverlapped.value().get().getScriptManager().emitEvent(
        "overlapped", this->_object.getName());
}

void Movement::cancelMovement() {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_isTo = false;
}

bool Movement::isMoving() const { return this->_isTo; }

float Movement::getSpeed() const { return this->_speed; }

void Movement::setSpeed(float speed) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_speed = speed;
}

void Movement::update() {
  if (this->_isTo) {
    Render::Vector3f position = this->_object.getTransform().getPosition();
    Render::Vector2f normal = Render::Utils::Vector::getNormal(
        {position.getX(), position.getY()}, this->_to);
    this->move(normal, this->_speed);
    const std::lock_guard<std::mutex> lock(this->_mutex);
    this->_isTo = true;
    Render::Vector3f newPosition = this->_object.getTransform().getPosition();
    Render::Vector3f normal3f(normal.getX(), normal.getY(), 0);
    Render::Vector3f speed3f(this->_speed, this->_speed, this->_speed);
    Render::Vector3f round = normal3f * speed3f * getDeltaTime();
    round.set(abs(round.getX()) + 1, abs(round.getY()) + 1, 0);
    Render::Vector3f to3f = {this->_to.getX(), this->_to.getY(), 0};
    Render::Vector3f roundPosition = newPosition - to3f;
    roundPosition.set(abs(roundPosition.getX()), abs(roundPosition.getY()), 0);
    if (round.getX() > roundPosition.getX() &&
        round.getY() > roundPosition.getY())
      this->_isTo = false;
  }
}

const Render::Clock &Movement::getClock() const { return this->_clock; }

Render::Clock &Movement::getClock() { return this->_clock; }

Render::Vector3f Movement::getDeltaTime() {
  return {static_cast<float>(this->_clock.getMicroSeconds()) / 1000000,
          static_cast<float>(this->_clock.getMicroSeconds()) / 1000000,
          static_cast<float>(this->_clock.getMicroSeconds()) / 1000000};
}
} // namespace Uniti::Game
