//
// Created by youba on 25/09/2023.
//

#include <SFML/Window/Event.hpp>
#include "UnitiGame.hpp"
#include <iostream>

namespace UnitiGameEngine {
    std::unique_ptr<Uniti> Uniti::_instance = nullptr;

    Uniti &Uniti::getInstance()
    {
        if (!_instance)
            throw std::runtime_error("error");
        return *_instance;
    }

    void Uniti::initGameProject(const std::string &projectPath) {
        Uniti::_instance.reset(new Uniti(projectPath));
    }

    Uniti::Uniti(const std::string &projectPath): _projectInfo(projectPath), _projectPath(projectPath) { }

    void Uniti::start() {
        sf::Event event;
        const sf::Color background(255, 255, 255);

        this->_sceneManager.init();
        this->_window.create(sf::VideoMode(
                this->_projectInfo.width,
                this->_projectInfo.height
        ), this->_projectInfo.titleWindow);
        this->_window.setFramerateLimit(this->_projectInfo.framerateLimit);
        while (this->_window.isOpen()) {
            this->_clock.restart();
            while (this->_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    this->_window.close();
                this->_input.checkEvents();
            }
            this->_window.clear(background);
            this->_sceneManager.update();
            this->_window.display();
        }
        this->_window.close();
    }

    const ProjectInfo &Uniti::getProjectInfo() const {
        return this->_projectInfo;
    }

    ScriptFactory &Uniti::getScriptFactory() {
        return this->_scriptFactory;
    }

    const SceneManager &Uniti::getSceneManager() const {
        return this->_sceneManager;
    }

    SceneManager &Uniti::getSceneManager() {
        return this->_sceneManager;
    }

    sf::Time Uniti::getDeltaTime() {
        return this->_clock.getElapsedTime();
    }

    const sf::RenderWindow &Uniti::getWindow() const {
        return this->_window;
    }

    sf::RenderWindow &Uniti::getWindow() {
        return this->_window;
    }

    ProjectInfo &Uniti::getProjectInfo() {
        return this->_projectInfo;
    }

    const Input &Uniti::getInput() const {
        return this->_input;
    }

    Input &Uniti::getInput() {
        return this->_input;
    }
}