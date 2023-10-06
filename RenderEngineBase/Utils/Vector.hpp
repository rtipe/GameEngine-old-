//
// Created by youba on 05/10/2023.
//

#pragma once


#include "Vector2i.hpp"
#include "Vector2f.hpp"
#include "Vector3f.hpp"

namespace Uniti::Render::Utils {
    class Vector {
    public:
        static float getDistance(const Uniti::Render::Vector2i &a, const Uniti::Render::Vector2i &b);
        static float getDistance(const Uniti::Render::Vector2f &a, const Uniti::Render::Vector2f &b);
        static float getDistance(const Uniti::Render::Vector3f &a, const Uniti::Render::Vector3f &b);
        static Uniti::Render::Vector2f getNormal(const Uniti::Render::Vector2i &base, const Uniti::Render::Vector2i &direction);
        static Uniti::Render::Vector2f getNormal(const Uniti::Render::Vector2f &base, const Uniti::Render::Vector2f &direction);
        static Uniti::Render::Vector3f getNormal(const Uniti::Render::Vector3f &base, const Uniti::Render::Vector3f &direction);
    };
}
