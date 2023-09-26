//
// Created by youba on 25/09/2023.
//

#include <fstream>
#include <SFML/Window/Event.hpp>
#include "UnitiGame.hpp"

namespace UnitiGameEngine {

    Uniti::Uniti(const std::string &projectPath) {
        std::ifstream file(projectPath);
        Json::Value information;
        file >> information;
        this->_projectInfo = ProjectInfo(information);
        this->_window.create(sf::VideoMode(
                this->_projectInfo.width,
                this->_projectInfo.height
        ), this->_projectInfo.titleWindow);
        this->_window.setFramerateLimit(60);
    }

    void Uniti::start() {
        sf::Event event;
        const sf::Color background(255, 255, 255);

        while (this->_window.isOpen()) {
            this->_clock.restart();
            while (this->_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    this->_window.close();
                // TODO: Mettre l'update de l'object input
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
}