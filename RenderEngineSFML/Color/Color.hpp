//
// Created by youba on 05/10/2023.
//

#pragma once


#include <json/value.h>
#include <mutex>

namespace Uniti::Render {
    class Color {
    public:
        Color();
        Color(const Json::Value &value);
        Color(const Color &color);
        Color(int r, int g, int b);
        Color(int r, int g, int b, int a);
        int getR() const;
        int getG() const;
        int getB() const;
        int getA() const;
        void setR(int value);
        void setG(int value);
        void setB(int value);
        void setA(int value);
        void set(int r, int g, int b);
        void set(int r, int g, int b, int a);
    private:
        int _r;
        int _g;
        int _b;
        int _a;
        std::mutex _mutex;
    };
}
