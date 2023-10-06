//
// Created by youba on 05/10/2023.
//

#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Uniti::Game {
    class Object;
    class ObjectManager {
    public:
        void add(std::unique_ptr<Object> object);
        void remove(const std::string &name);
        const std::vector<std::unique_ptr<Object>> &getObjects() const;
        std::vector<std::unique_ptr<Object>> &getObjects();
        void update();
    private:
    };
}
