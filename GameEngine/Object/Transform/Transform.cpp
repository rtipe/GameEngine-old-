//
// Created by youba on 05/10/2023.
//

#include "Transform.hpp"

namespace Uniti::Game {
    Transform::Transform() = default;

    Transform::Transform(const Json::Value &value)
        : _position(value["position"]),
          _scale(value["scale"]),
          _origin(value["origin"]),
          _rotation(value.get("rotation", 0).asFloat())
    {
    }

    const Render::Vector3f &Transform::getPosition() const
    {
        return this->_position;
    }

    Render::Vector3f &Transform::getPosition()
    {
        return this->_position;
    }

    const Render::Vector2f &Transform::getScale() const
    {
        return this->_scale;
    }

    Render::Vector2f &Transform::getScale()
    {
        return this->_scale;
    }

    const Render::Vector2f &Transform::getOrigin() const
    {
        return this->_origin;
    }

    Render::Vector2f &Transform::getOrigin()
    {
        return this->_origin;
    }

    float Transform::getRotation() const
    {
        return this->_rotation;
    }

    void Transform::setRotation(float value)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_rotation = value;
    }

    Transform::Transform(const Transform &transform)
        : _rotation(transform.getRotation()),
          _origin(transform.getOrigin()),
          _scale(transform.getScale()),
          _position(transform.getPosition())
    {
    }
} // namespace Uniti::Game