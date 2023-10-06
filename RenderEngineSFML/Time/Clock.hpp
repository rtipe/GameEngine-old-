//
// Created by youba on 05/10/2023.
//

#pragma once

#include <chrono>

namespace Uniti::Render {
    class Clock {
    public:
        void restart();
        long long getSeconds() const;
        long long getMilliSeconds() const;
        long long getMicroSeconds() const;
        void pause();
        void start();
    private:
        std::chrono::high_resolution_clock::time_point _start;
        std::chrono::high_resolution_clock::time_point _pause;
        bool _paused = false;
    };
}
