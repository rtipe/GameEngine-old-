//
// Created by youba on 26/09/2023.
//

#pragma once

#include "../Object/IObject.hpp"

namespace UnitiGameEngine {
    class Displayer {
        public:
            Displayer() {}
            void display();
            void add(IObject &object);
            void clear();
            void sort();
        private:
            std::vector<std::reference_wrapper<IObject>> _objects;
    };
}
