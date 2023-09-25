//
// Created by youba on 25/09/2023.
//

#pragma once

namespace UnitiGameEngine {
    class IScript {
        public:
            virtual ~IScript() = default;
            virtual void start() = 0;
            virtual void update() = 0;
    };
}