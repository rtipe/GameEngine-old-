//
// Created by youba on 05/10/2023.
//

#pragma once

#include <json/value.h>
#include <mutex>

namespace Uniti::Render {
    class Vector2f {
    public:
        Vector2f();
        Vector2f(const Vector2f &vector);
        Vector2f(float x, float y);
        Vector2f(const Json::Value &value);
        float getX() const;
        float getY() const;
        void setX(float value);
        void setY(float value);
        void set(float x, float y);
        Vector2f operator+(const Vector2f &other) const;
        Vector2f operator-(const Vector2f &other) const;
        Vector2f operator*(const Vector2f &other) const;
        Vector2f operator/(const Vector2f &other) const;
        Vector2f &operator=(const Vector2f &other);
    private:
        std::mutex _mutex;
        float _x;
        float _y;
    };
} // Uniti
// Render
