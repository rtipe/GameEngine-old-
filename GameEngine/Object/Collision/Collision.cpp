#define IndentWidth 4
//
// Created by youba on 05/10/2023.
//

#include "Collision.hpp"

#include "Object.hpp"

namespace Uniti::Game {
Collision::Collision(Transform &transform) : _transform(transform) {}

Collision::Collision(const Json::Value &value, Transform &transform)
    : _transform(transform) {
  this->_isOverlap = value.get("isOverlap", false).asBool();
  for (const auto &box : value["boxs"])
    this->_collisions.push_back(box);
}

Collision::Collision(const std::vector<Render::Box> &collisions,
                     Transform &transform)
    : _transform(transform) {
  for (const auto &box : collisions) {
    this->_collisions.push_back(box);
  }
}

Collision::Collision(const Render::Box &box, Transform &transform)
    : _transform(transform) {
  this->_collisions.push_back(box);
}

const std::vector<Render::Box> &Collision::getBox() const {
  return this->_collisions;
}

std::vector<Render::Box> &Collision::getBox() { return this->_collisions; }

bool Collision::isInside(const Render::Vector2f &point) const {
  for (const auto &box : this->_collisions) {
    if (box.isInside(point, this->_transform.getPosition()))
      return true;
  }
  return false;
}

bool Collision::isInside(const Render::Box &box,
                         const Render::Vector3f &position) const {
  for (const auto &inBox : this->_collisions) {
    if (inBox.isInside(box, this->_transform.getPosition(), position))
      return true;
  }
  return false;
}

void Collision::addBox(const Render::Box &box) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_collisions.push_back(box);
}

bool Collision::isOverlap() const { return this->_isOverlap; }

void Collision::setOverlap(bool isOverlap) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_isOverlap = isOverlap;
}

bool Collision::isInside(const Object &object) const {
  for (const auto &inBox : this->_collisions) {
    for (const auto &outBox : object.getCollision().getBox()) {
      if (inBox.isInside(outBox, this->_transform.getPosition(),
                         object.getTransform().getPosition()))
        return true;
    }
  }
  return false;
}
} // namespace Uniti::Game