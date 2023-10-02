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
#include "Event/Input.hpp"

namespace UnitiGameEngine {
    class Uniti {
        public:
            void start();
            const ProjectInfo &getProjectInfo() const;
            ProjectInfo &getProjectInfo();
            const SceneManager &getSceneManager() const;
            SceneManager &getSceneManager();
            ScriptFactory &getScriptFactory();
            sf::Time getDeltaTime();
            const sf::RenderWindow &getWindow() const;
            sf::RenderWindow &getWindow();
            static Uniti &getInstance();
            static void initGameProject(const std::string &projectPath);
            const Input &getInput() const;
            Input &getInput();
        private:
            Uniti(const std::string &projectPath);
            static std::unique_ptr<Uniti> _instance;
            SceneManager _sceneManager;
            ProjectInfo _projectInfo;
            sf::RenderWindow _window;
            sf::Clock _clock;
            ScriptFactory _scriptFactory;
            Input _input;
            std::string _projectPath;
    };
}
