//
// Created by youba on 05/10/2023.
//

#include "Window.hpp"

#include <iostream>

#include "IPrintable.hpp"
#include "Input.hpp"
#include "Mouse.hpp"

namespace Uniti::Render {
bool Window::isOpen() const { return this->_window.isOpen(); }

void Window::close() { this->_window.close(); }

void Window::display() {
  Input::clearEvents();
  Mouse::clearEvents();
  while (this->_window.pollEvent(this->_event)) {
    if (this->_event.type == sf::Event::Closed) this->close();
    Input::update(*this);
    Mouse::update(*this);
  }
  std::sort(this->_printable.begin(), this->_printable.end(),
            [](IPrintable &printable1, IPrintable &printable2) {
              return printable1.getPosition().getZ() <
                     printable2.getPosition().getZ();
            });
  this->_window.clear({0, 0, 0});
  for (const auto &printable : this->_printable) printable.get().display(*this);
  this->_window.display();
  this->_printable.clear();
}

void Window::create(const Json::Value &value) {
  int width = value.get("width", 1920).asInt();
  int height = value.get("height", 1080).asInt();
  int framerateLimit = value.get("framerateLimit", 60).asInt();
  std::string iconPath = value.get("icon", "").asString();
  std::string title = value.get("title", "undefined").asString();

  this->_window.create(sf::VideoMode(width, height), title);
  this->_window.setFramerateLimit(framerateLimit);
  if (this->_icon.loadFromFile(iconPath))
    this->_window.setIcon(this->_icon.getSize().x, this->_icon.getSize().y,
                          this->_icon.getPixelsPtr());
}

sf::Event &Window::getEvent() { return this->_event; }

sf::RenderWindow &Window::getRenderWindow() { return this->_window; }

void Window::print(IPrintable &printable) {
  this->_printable.emplace_back(printable);
}
}  // namespace Uniti::Render