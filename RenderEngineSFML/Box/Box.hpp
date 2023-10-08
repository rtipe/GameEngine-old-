//
// Created by youba on 05/10/2023.
//

#pragma once


#include <json/value.h>
#include "Vector2f.hpp"
#include "Vector3f.hpp"

namespace Uniti::Render {
    class Box {
    public:
        Box(const Json::Value &value);
        Box(float x, float y, float width, float height);
        const Vector2f &getPosition() const;
        const Vector2f &getDimension() const;
        void setPosition(const Vector2f &position);
        void setDimension(const Vector2f &dimension);
        void setX(float x);
        void setY(float y);
        void setWidth(float width);
        void setHeight(float height);
        bool isInside(const Vector2f &point) const;
        bool isInside(const Vector2f &point, const Vector3f &parent) const;
        bool isInside(const Box &box) const;
        bool isInside(const Box &box, const Vector3f &parentA, const Vector3f &parentB) const;
    private:
        Vector2f _position;
        Vector2f _dimension;
    };
}
