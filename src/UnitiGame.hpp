//
// Created by youba on 25/09/2023.
//

#pragma once

#include <string>
#include <vector>
#include "Object/IObject.hpp"
#include "Scene/SceneManager.hpp"

namespace UnitiGameEngine {
    class Uniti {
        public:
            Uniti(const std::string &projectPath);
            void update();
            void getProjectInfo();
            const std::vector<std::unique_ptr<IObject>> &getAllObjects() const;
            std::vector<std::unique_ptr<IObject>> &getAllObjects();
            const SceneManager &getSceneManager() const;
            SceneManager &getSceneManager();
        private:
            std::vector<std::unique_ptr<IObject>> _objects;
            SceneManager _sceneManager;
    };
}
