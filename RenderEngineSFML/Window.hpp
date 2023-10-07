//
// Created by youba on 05/10/2023.
//

#pragma once

#include <json/value.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace Uniti::Render {
    class IPrintable;
    class Window {
    public:
        bool isOpen() const;
        void close();
        void display();
        void create(const Json::Value &value);
        void print(IPrintable &printable);
        sf::Event &getEvent();
        sf::RenderWindow &getRenderWindow();
    private:
        sf::Event _event;
        sf::Image _icon;
        sf::RenderWindow _window;
        std::vector<std::reference_wrapper<IPrintable>> _printable;
    };
}
