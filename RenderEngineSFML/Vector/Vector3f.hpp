//
// Created by youba on 05/10/2023.
//

#pragma once


#include <mutex>
#include <json/value.h>

namespace Uniti::Render {
    class Vector3f {
    public:
        Vector3f();
        Vector3f(const Vector3f &vector);
        Vector3f(float x, float y, float z);
        Vector3f(const Json::Value &value);
        float getX() const;
        float getY() const;
        float getZ() const;
        void setX(float value);
        void setY(float value);
        void setZ(float value);
        void set(float x, float y, float z);
        Vector3f operator+(const Vector3f &other) const;
        Vector3f operator-(const Vector3f &other) const;
        Vector3f operator*(const Vector3f &other) const;
        Vector3f operator/(const Vector3f &other) const;
        Vector3f &operator=(const Vector3f &other);
    private:
        std::mutex _mutex;
        float _x;
        float _y;
        float _z;
    };
}
