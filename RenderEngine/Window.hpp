//
// Created by youba on 05/10/2023.
//

#pragma once


#include <json/value.h>

namespace Uniti::Render {
    class Window {
    public:
        bool isOpen() const;
        void close();
        void display();
        void create(const Json::Value &value);
    };
}
