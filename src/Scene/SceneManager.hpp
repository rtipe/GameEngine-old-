//
// Created by youba on 25/09/2023.
//

#pragma once

#include <optional>
#include "ScenePath.hpp"
#include "../Displayer/Displayer.hpp"

namespace UnitiGameEngine {
    class SceneManager {
        public:
            SceneManager();
            const Scene &getCurrentScene() const;
            Scene &getCurrentScene();
            const Scene &getGlobalScene() const;
            Scene &getGlobalScene();
            const std::vector<ScenePath> &getAllScenes() const;
            const ScenePath &getScenePath(const std::string &name) const;
            void addScenePath(ScenePath &scenePath);
            bool removeScenePath(const std::string &name);
            bool changeScene(const std::string &name);
            void update();
            void init();
            const Displayer &getDisplayer() const;
            Displayer &getDisplayer();
        private:
            std::unique_ptr<Scene> _globalScene;
            std::unique_ptr<Scene> _currentScene;
            std::optional<ScenePath> _nextScene;
            Displayer _displayer;
    };
}
