//
// Created by youba on 05/10/2023.
//

#include "Vector.hpp"


namespace Uniti::Render::Utils {
    float Vector::getDistance(const Vector2i &a, const Vector2i &b) {
        auto dx = static_cast<float>(a.getX() - b.getX());
        auto dy = static_cast<float>(a.getY() - b.getY());
        return std::sqrt(dx * dx + dy * dy);
    }

    float Vector::getDistance(const Vector2f &a, const Vector2f &b) {
        float dx = a.getX() - b.getX();
        float dy = a.getY() - b.getY();
        return std::sqrt(dx * dx + dy * dy);
    }

    float Vector::getDistance(const Vector3f &a, const Vector3f &b) {
        float dx = a.getX() - b.getX();
        float dy = a.getY() - b.getY();
        float dz = a.getZ() - b.getZ();
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    Uniti::Render::Vector2f Vector::getNormal(const Vector2i &base, const Vector2i &direction) {
        Vector2i normalVector = direction - base;
        Vector2f result(static_cast<float>(normalVector.getX()), static_cast<float>(normalVector.getY()));
        auto length = std::sqrt(result.getX() * result.getX() + result.getY() * result.getY());
        if (length != 0) {
            result.setX(result.getX() / length);
            result.setY(result.getY() / length);
        } else {
            return {0, 0};
        }
        return result;
    }

    Uniti::Render::Vector2f Vector::getNormal(const Vector2f &base, const Vector2f &direction) {
        Vector2f normalVector = direction - base;
        auto length = std::sqrt(normalVector.getX() * normalVector.getX() + normalVector.getY() * normalVector.getY());
        if (length != 0) {
            normalVector.setX(normalVector.getX() / length);
            normalVector.setY(normalVector.getY() / length);
        } else {
            return {0, 0};
        }
        return normalVector;
    }

    Uniti::Render::Vector3f Vector::getNormal(const Vector3f &base, const Vector3f &direction) {
        Vector3f normalVector = direction - base;
        auto length = std::sqrt(normalVector.getX() * normalVector.getX() + normalVector.getY() * normalVector.getY());
        if (length != 0) {
            normalVector.setX(normalVector.getX() / length);
            normalVector.setY(normalVector.getY() / length);
        } else {
            return {0, 0, 0};
        }
        return normalVector;
    }
}