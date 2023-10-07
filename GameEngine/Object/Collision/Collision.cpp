//
// Created by youba on 05/10/2023.
//

#include "Collision.hpp"


namespace Uniti::Game {
    Collision::Collision() { }

    Collision::Collision(const Json::Value &value) {
        for (const auto &box : value)
            this->_collisions.push_back(box);
    }

    Collision::Collision(const std::vector<Render::Box> &collisions) {
        for (const auto &box : collisions) {
            this->_collisions.push_back(box);
        }
    }

    Collision::Collision(const Render::Box &box) {
        this->_collisions.push_back(box);
    }

    const std::vector<Render::Box> &Collision::getBox() const {
        return this->_collisions;
    }

    std::vector<Render::Box> &Collision::getBox() {
        return this->_collisions;
    }

    bool Collision::isInside(const Render::Vector2f &point) const {
        for (const auto &box : this->_collisions) {
            if (box.isInside(point))
                return true;
        }
        return false;
    }

    bool Collision::isInside(const Render::Box &box) const {
        for (const auto &inBox : this->_collisions) {
            if (inBox.isInside(box))
                return true;
        }
        return false;
    }

    void Collision::addBox(const Render::Box &box) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_collisions.push_back(box);
    }
}