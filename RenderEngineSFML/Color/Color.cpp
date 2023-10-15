//
// Created by youba on 05/10/2023.
//

#include "Color.hpp"

namespace Uniti::Render {
    Color::Color() : _r(0), _g(0), _b(0), _a(255)
    {
    }

    Color::Color(const Json::Value &value)
    {
        this->_r = value.get("r", 0).asInt();
        this->_b = value.get("b", 0).asInt();
        this->_g = value.get("g", 0).asInt();
        this->_a = value.get("a", 255).asInt();
    }

    Color::Color(const Color &color)
        : _r(color.getR()),
          _g(color.getG()),
          _b(color.getB()),
          _a(color.getA())
    {
    }

    Color::Color(int r, int g, int b) : _r(r), _g(g), _b(b), _a(255)
    {
    }

    Color::Color(int r, int g, int b, int a) : _r(r), _g(g), _b(b), _a(a)
    {
    }

    int Color::getR() const
    {
        return this->_r;
    }

    int Color::getG() const
    {
        return this->_g;
    }

    int Color::getB() const
    {
        return this->_b;
    }

    int Color::getA() const
    {
        return this->_a;
    }

    void Color::setR(int value)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_r = value;
    }

    void Color::setG(int value)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_g = value;
    }

    void Color::setB(int value)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_b = value;
    }

    void Color::setA(int value)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_a = value;
    }

    void Color::set(int r, int g, int b)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_r = r;
        this->_g = g;
        this->_b = b;
    }

    void Color::set(int r, int g, int b, int a)
    {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_r = r;
        this->_g = g;
        this->_b = b;
        this->_a = a;
    }
} // namespace Uniti::Render