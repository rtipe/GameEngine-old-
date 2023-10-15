//
// Created by youba on 05/10/2023.
//

#include "Vector2f.hpp"

namespace Uniti {
    namespace Render {
        Vector2f::Vector2f() : _x(0), _y(0)
        {
        }

        Vector2f::Vector2f(const Vector2f &vector) : _x(vector.getX()), _y(vector.getY())
        {
        }

        Vector2f::Vector2f(float x, float y) : _x(x), _y(y)
        {
        }

        Vector2f::Vector2f(const Json::Value &value)
        {
            this->_x = value.get("x", 0).asFloat();
            this->_y = value.get("y", 0).asFloat();
        }

        float Vector2f::getX() const
        {
            return this->_x;
        }

        float Vector2f::getY() const
        {
            return this->_y;
        }

        void Vector2f::setX(float value)
        {
            const std::lock_guard<std::mutex> lock(this->_mutex);
            this->_x = value;
        }

        void Vector2f::setY(float value)
        {
            const std::lock_guard<std::mutex> lock(this->_mutex);
            this->_y = value;
        }

        void Vector2f::set(float x, float y)
        {
            const std::lock_guard<std::mutex> lock(this->_mutex);
            this->_x = x;
            this->_y = y;
        }

        Vector2f Vector2f::operator+(const Vector2f &other) const
        {
            return {this->_x + other.getX(), this->_y + other.getY()};
        }

        Vector2f Vector2f::operator-(const Vector2f &other) const
        {
            return {this->_x - other.getX(), this->_y - other.getY()};
        }

        Vector2f Vector2f::operator*(const Vector2f &other) const
        {
            return {this->_x * other.getX(), this->_y * other.getY()};
        }

        Vector2f Vector2f::operator/(const Vector2f &other) const
        {
            return {this->_x / other.getX(), this->_y / other.getY()};
        }

        Vector2f &Vector2f::operator=(const Vector2f &other)
        {
            const std::lock_guard<std::mutex> lock(this->_mutex);
            this->_x = other.getX();
            this->_y = other.getY();
            return *this;
        }
    } // namespace Render
} // namespace Uniti

std::ostream &operator<<(std::ostream &os, const Uniti::Render::Vector2f &vector)
{
    os << "x = " << vector.getX() << " y = " << vector.getY() << std::endl;
    return os;
}