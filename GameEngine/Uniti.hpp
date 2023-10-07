//
// Created by youba on 05/10/2023.
//

#pragma once

#include "ProjectInfo.hpp"
#include "SceneManager.hpp"
#include "ScriptFactory.hpp"
#include "Window.hpp"
#include "Sound.hpp"

namespace Uniti::Game {
    class Core {
    public:
        static void start();
        static ProjectInfo &getProjectInfo();
        static SceneManager &getSceneManager();
        static ScriptFactory &getScriptFactory();
        static Render::Window &getWindow();
        static Render::Sound &getSound();
        static void initProject(const std::string &projectPath);
    private:
        Core(const std::string &projectPath);
        static std::unique_ptr<Core> _instance;
        Render::Window _window;
        ProjectInfo _projectInfo;
        SceneManager _sceneManager;
        ScriptFactory _scriptFactory;
        std::string _projectPath;
        Render::Sound _sound;
    };
}
