//
// Created by youba on 25/09/2023.
//

#pragma once

#include "Position.hpp"
#include "Scale.hpp"
#include "Rotation.hpp"

namespace UnitiGameEngine {
    struct Transform {
        Position position;
        Scale scale;
        Rotation rotation;
    };
}