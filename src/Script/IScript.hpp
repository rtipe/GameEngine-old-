//
// Created by youba on 25/09/2023.
//

#pragma once

#include <json/value.h>

namespace UnitiGameEngine {
    class IScript {
        public:
            virtual ~IScript() = default;
            virtual void start() = 0;
            virtual void update() = 0;
            virtual void awake(const Json::Value &value) = 0;
    };
}