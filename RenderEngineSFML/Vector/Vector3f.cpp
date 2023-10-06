//
// Created by youba on 05/10/2023.
//

#include "Vector3f.hpp"

namespace Uniti {
    namespace Render {
        Vector3f::Vector3f(): _x(0), _y(0), _z(0) { }

        Vector3f::Vector3f(const Vector3f &vector): _x(vector.getX()), _y(vector.getY()), _z(vector.getZ()) { }

        Vector3f::Vector3f(float x, float y, float z): _x(x), _y(y), _z(z) { }

        Vector3f::Vector3f(const Json::Value &value) {
            this->_x = value.get("x", 0).asFloat();
            this->_y = value.get("y", 0).asFloat();
            this->_z = value.get("z", 0).asFloat();
        }

        float Vector3f::getX() const {
            return this->_x;
        }

        float Vector3f::getY() const {
            return this->_y;
        }

        float Vector3f::getZ() const {
            return this->_z;
        }

        void Vector3f::setX(float value) {
            const std::lock_guard<std::mutex> lock(this->_mutex);
            this->_x = value;
        }

        void Vector3f::setY(float value) {
            const std::lock_guard<std::mutex> lock(this->_mutex);
            this->_y = value;
        }

        void Vector3f::setZ(float value) {
            const std::lock_guard<std::mutex> lock(this->_mutex);
            this->_z = value;
        }

        void Vector3f::set(float x, float y, float z) {
            const std::lock_guard<std::mutex> lock(this->_mutex);
            this->_x = x;
            this->_y = y;
            this->_z = z;
        }

        Vector3f Vector3f::operator+(const Vector3f &other) const {
            return {this->_x + other.getX(), this->_y + other.getY(), this->_z + other.getZ()};
        }

        Vector3f Vector3f::operator-(const Vector3f &other) const {
            return {this->_x - other.getX(), this->_y - other.getY(), this->_z - other.getZ()};
        }

        Vector3f Vector3f::operator*(const Vector3f &other) const {
            return {this->_x * other.getX(), this->_y * other.getY(), this->_z * other.getZ()};
        }

        Vector3f Vector3f::operator/(const Vector3f &other) const {
            return {this->_x / other.getX(), this->_y / other.getY(), this->_z / other.getZ()};
        }

        Vector3f &Vector3f::operator=(const Vector3f &other) {
            const std::lock_guard<std::mutex> lock(this->_mutex);
            this->_x = other.getX();
            this->_y = other.getY();
            this->_z = other.getZ();
            return *this;
        }
    }
}