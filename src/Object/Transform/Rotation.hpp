//
// Created by youba on 25/09/2023.
//

#pragma once

namespace UnitiGameEngine {
    struct Rotation {
        Rotation(): angle(0) {}
        Rotation(float _angle): angle(_angle) {}
        float angle;
    };
}