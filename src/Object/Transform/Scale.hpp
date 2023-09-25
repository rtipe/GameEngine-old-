//
// Created by youba on 25/09/2023.
//

#pragma once

namespace UnitiGameEngine {
    struct Scale {
        Scale(): x(0), y(0) {}
        Scale(float _x, float _y): x(_x), y(_y) {}
        float x;
        float y;
    };
}
