//
// Created by youba on 05/10/2023.
//

#include "Uniti.hpp"

namespace Uniti::Game {
    std::unique_ptr<Core> Core::_instance = nullptr;

    void Core::start()
    {
        if (!Core::_instance)
            throw std::invalid_argument("core not initialized");
        _instance->_sceneManager.init();
        _instance->_window.create(_instance->_projectInfo.data["windowInfos"]);
        while (_instance->_window.isOpen()) {
            _instance->_sceneManager.update();
            _instance->_window.display();
            _instance->_network.update();
        }
    }

    ProjectInfo &Core::getProjectInfo()
    {
        if (!Core::_instance)
            throw std::invalid_argument("core not initialized");
        return Core::_instance->_projectInfo;
    }

    SceneManager &Core::getSceneManager()
    {
        if (!Core::_instance)
            throw std::invalid_argument("core not initialized");
        return Core::_instance->_sceneManager;
    }

    ScriptFactory &Core::getScriptFactory()
    {
        if (!Core::_instance)
            throw std::invalid_argument("core not initialized");
        return Core::_instance->_scriptFactory;
    }

    Render::Window &Core::getWindow()
    {
        if (!Core::_instance)
            throw std::invalid_argument("core not initialized");
        return Core::_instance->_window;
    }

    void Core::initProject(const std::string &projectPath)
    {
        Core::_instance.reset(new Core(projectPath));
    }

    Core::Core(const std::string &projectPath)
        : _projectInfo(projectPath),
          _projectPath(projectPath),
          _network(_projectInfo.port, _projectInfo.latence)
    {
        this->_network.start();
    }

    Render::Sound &Core::getSound()
    {
        if (!Core::_instance)
            throw std::invalid_argument("core not initialized");
        return Core::_instance->_sound;
    }

    Network &Core::getNetwork()
    {
        if (!Core::_instance)
            throw std::invalid_argument("core not initialized");
        return Core::_instance->_network;
    }
} // namespace Uniti::Game