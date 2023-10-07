//
// Created by youba on 05/10/2023.
//

#pragma once


#include <optional>
#include "Scene.hpp"
#include "ScenePath.hpp"

namespace Uniti::Game {
    class SceneManager {
    public:
        const Scene &getCurrentScene() const;
        Scene &getCurrentScene();
        const Scene &getGlobalScene() const;
        Scene &getGlobalScene();
        const std::vector<ScenePath> &getAllScenes() const;
        const ScenePath &getScenePath(const std::string &name) const;
        void addScenePath(ScenePath &scenePath);
        bool changeScene(const std::string &name);
        void update();
        void init();
        Json::Value getSceneValue(const ScenePath &scenePath) const;
    private:
        std::unique_ptr<Scene> _globalScene;
        std::unique_ptr<Scene> _currentScene;
        std::optional<ScenePath> _nextScene = std::nullopt;
        std::mutex _mutex;
    };
}
