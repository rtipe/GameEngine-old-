//
// Created by youba on 05/10/2023.
//

#pragma once

#include <memory>
#include <string>
#include <vector>
#include <json/value.h>
#include <mutex>
#include "Scene.hpp"

namespace Uniti::Game {
    class Object;
    class Scene;
    class ObjectManager {
    public:
        ObjectManager(const Json::Value &value, Scene &scene);
        void add(std::unique_ptr<Object> object);
        void remove(const std::string &name);
        const std::vector<std::unique_ptr<Object>> &getObjects() const;
        std::vector<std::unique_ptr<Object>> &getObjects();
        void update();
    private:
        std::vector<std::unique_ptr<Object>> _objects;
        std::mutex _mutex;
        Scene &_scene;
    };
}
