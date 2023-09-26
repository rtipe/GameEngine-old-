//
// Created by youba on 25/09/2023.
//

#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Object/IObject.hpp"
#include "Scene/SceneManager.hpp"
#include "ProjectInfo.hpp"
#include "Script/ScriptFactory.hpp"

namespace UnitiGameEngine {
    class Uniti {
        public:
            Uniti(const std::string &projectPath);
            void start();
            const ProjectInfo &getProjectInfo() const;
            ProjectInfo &getProjectInfo();
            const SceneManager &getSceneManager() const;
            SceneManager &getSceneManager();
            sf::Time getDeltaTime();
            const sf::RenderWindow &getWindow() const;
            sf::RenderWindow &getWindow();
        private:
            SceneManager _sceneManager;
            ProjectInfo _projectInfo;
            sf::RenderWindow _window;
            sf::Clock _clock;
            ScriptFactory _scriptFactory;
    };
}
