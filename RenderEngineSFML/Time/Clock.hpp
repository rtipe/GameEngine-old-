//
// Created by youba on 05/10/2023.
//

#pragma once

#include <chrono>
#include <mutex>

namespace Uniti::Render {
    class Clock {
    public:
        Clock();
        void restart();
        long long getSeconds() const;
        long long getMilliSeconds() const;
        long long getMicroSeconds() const;
        void pause();
        void start();
    private:
        std::mutex _mutex;
        std::chrono::high_resolution_clock::time_point _start;
        std::chrono::high_resolution_clock::time_point _pause;
        bool _paused = false;
    };
}
