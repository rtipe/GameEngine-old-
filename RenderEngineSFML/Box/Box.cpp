//
// Created by youba on 05/10/2023.
//

#include "Box.hpp"


namespace Uniti::Render {
    Box::Box(const Json::Value &value) {
        this->_position.set(value.get("x", 0).asFloat(), value.get("y", 0).asFloat());
        this->_position.set(value.get("width", 0).asFloat(), value.get("height", 0).asFloat());
    }

    Box::Box(float x, float y, float left, float top): _position(x, y), _dimension(left, top) { }

    const Vector2f &Box::getPosition() const {
        return this->_position;
    }

    const Vector2f &Box::getDimension() const {
        return this->_dimension;
    }

    void Box::setPosition(const Vector2f &position) {
        this->_position = position;
    }

    void Box::setDimension(const Vector2f &dimension) {
        this->_dimension = dimension;
    }

    void Box::setX(float x) {
        this->_position.setX(x);
    }

    void Box::setY(float y) {
        this->_position.setY(y);
    }

    void Box::setWidth(float width) {
        this->_dimension.setX(width);
    }

    void Box::setHeight(float height) {
        this->_dimension.setY(height);
    }

    bool Box::isInside(const Vector2f &point) const {
        float left = this->_position.getX();
        float right = this->_position.getX() + this->_dimension.getX();
        float top = this->_position.getY();
        float bottom = this->_position.getY() + this->_dimension.getY();

        return (point.getX() >= left && point.getX() <= right && point.getY() >= top && point.getY() <= bottom);
    }

    bool Box::isInside(const Box &box) const {
        float thisLeft = this->_position.getX();
        float thisRight = this->_position.getX() + this->_dimension.getX();
        float thisTop = this->_position.getY();
        float thisBottom = this->_position.getY() + this->_dimension.getY();

        float otherLeft = box.getPosition().getX();
        float otherRight = box.getPosition().getX() + box.getDimension().getX();
        float otherTop = box.getPosition().getY();
        float otherBottom = box.getPosition().getY() + box.getDimension().getY();

        return (otherLeft >= thisLeft && otherRight <= thisRight && otherTop >= thisTop && otherBottom <= thisBottom);
    }
}