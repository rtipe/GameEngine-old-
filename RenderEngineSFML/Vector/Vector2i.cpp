//
// Created by youba on 05/10/2023.
//

#include "Vector2i.hpp"

namespace Uniti {
namespace Render {
Vector2i::Vector2i() : _x(0), _y(0) {}

Vector2i::Vector2i(const Vector2i &vector)
    : _x(vector.getX()), _y(vector.getY()) {}

Vector2i::Vector2i(int x, int y) : _x(x), _y(y) {}

Vector2i::Vector2i(const Json::Value &value) {
  this->_x = value.get("x", 0).asInt();
  this->_y = value.get("y", 0).asInt();
}

int Vector2i::getX() const { return this->_x; }

int Vector2i::getY() const { return this->_y; }

void Vector2i::setX(int value) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_x = value;
}

void Vector2i::setY(int value) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_y = value;
}

void Vector2i::set(int x, int y) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_x = x;
  this->_y = y;
}

Vector2i Vector2i::operator+(const Vector2i &other) const {
  return {this->_x + other.getX(), this->_y + other.getY()};
}

Vector2i Vector2i::operator-(const Vector2i &other) const {
  return {this->_x - other.getX(), this->_y - other.getY()};
}

Vector2i Vector2i::operator*(const Vector2i &other) const {
  return {this->_x * other.getX(), this->_y * other.getY()};
}

Vector2i Vector2i::operator/(const Vector2i &other) const {
  return {this->_x / other.getX(), this->_y / other.getY()};
}

Vector2i &Vector2i::operator=(const Vector2i &other) {
  const std::lock_guard<std::mutex> lock(this->_mutex);
  this->_x = other.getX();
  this->_y = other.getY();
  return *this;
}
}  // namespace Render
}  // namespace Uniti

std::ostream &operator<<(std::ostream &os,
                         const Uniti::Render::Vector2i &vector) {
  os << "x = " << vector.getX() << " y = " << vector.getY() << std::endl;
  return os;
}