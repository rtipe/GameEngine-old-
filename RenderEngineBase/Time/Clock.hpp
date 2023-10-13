//
// Created by youba on 05/10/2023.
//

#pragma once

namespace Uniti::Render {
    class Clock {
    public:
        void restart();
        long long getSeconds() const;
        long long getMilliSeconds() const;
        long long getMicroSeconds() const;
        void pause();
        void start();
    };
}
