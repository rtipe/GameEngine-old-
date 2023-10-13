//
// Created by youba on 05/10/2023.
//

#pragma once


#include <json/value.h>
#include <mutex>

namespace Uniti::Render {
    class Vector2i {
    public:
        Vector2i();
        Vector2i(const Vector2i &vector);
        Vector2i(int x, int y);
        Vector2i(const Json::Value &value);
        int getX() const;
        int getY() const;
        void setX(int value);
        void setY(int value);
        void set(int x, int y);
        Vector2i operator+(const Vector2i &other) const;
        Vector2i operator-(const Vector2i &other) const;
        Vector2i operator*(const Vector2i &other) const;
        Vector2i operator/(const Vector2i &other) const;
        Vector2i &operator=(const Vector2i &other);
    private:
        std::mutex _mutex;
        int _x;
        int _y;
    };
}

std::ostream& operator<<(std::ostream& os, const Uniti::Render::Vector2i& vector);
