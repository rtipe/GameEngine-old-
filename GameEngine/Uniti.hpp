//
// Created by youba on 05/10/2023.
//

#pragma once


#include "ProjectInfo.hpp"
#include "SceneManager.hpp"
#include "ScriptFactory.hpp"

namespace Uniti::Game {
    class Uniti {
    public:
        static void start();
        static ProjectInfo &getProjectInfo();
        static SceneManager &getSceneManager();
        static ScriptFactory &getScriptFactory();
        static Render::Window &getWindow();
        static void initProject(const std::string &projectPath);
    private:
        Uniti(const std::string &projectPath);
        static std::unique_ptr<Uniti> _instance;
        Render::Window _window;
        ProjectInfo _projectInfo;
        SceneManager _sceneManager;
        ScriptFactory _scriptFactory;
        std::string _projectPath;
    };
}
