//
// Created by youba on 26/09/2023.
//

#include <algorithm>
#include "Displayer.hpp"

namespace UnitiGameEngine {

    void Displayer::display() {
        this->sort();
        for (auto &object : this->_objects) {
            object.get().display();
        }
        this->clear();
    }

    void Displayer::add(IObject &object) {
        this->_objects.emplace_back(object);
    }

    void Displayer::clear() {
        this->_objects.clear();
    }

    void Displayer::sort() {
        std::sort(this->_objects.begin(), this->_objects.end(),
        [](IObject &object1, IObject &object2) {
            return object1.getTransform().position.z > object2.getTransform().position.z;
        });
    }
}
