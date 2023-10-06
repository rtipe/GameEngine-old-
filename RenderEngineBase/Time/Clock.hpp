//
// Created by youba on 05/10/2023.
//

#pragma once

namespace Uniti::Render {
    class Clock {
    public:
        void restart();
        float getSeconds() const;
        float getMilliSeconds() const;
        float getMicroSeconds() const;
        void pause();
    };
}
