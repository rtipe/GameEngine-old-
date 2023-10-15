# Utils Class

## Description

The `Utils` class provides utility functions related to vectors, including calculating distances and obtaining normal vectors.

## Member Functions

- `static float getDistance(const Uniti::Render::Vector2i &a, const Uniti::Render::Vector2i &b)`: Calculates the distance between two 2D integer vectors.
- `static float getDistance(const Uniti::Render::Vector2f &a, const Uniti::Render::Vector2f &b)`: Calculates the distance between two 2D floating-point vectors.
- `static float getDistance(const Uniti::Render::Vector3f &a, const Uniti::Render::Vector3f &b)`: Calculates the distance between two 3D floating-point vectors.
- `static Uniti::Render::Vector2f getNormal(const Uniti::Render::Vector2i &base, const Uniti::Render::Vector2i &direction)`: Calculates the normal vector between two 2D integer vectors.
- `static Uniti::Render::Vector2f getNormal(const Uniti::Render::Vector2f &base, const Uniti::Render::Vector2f &direction)`: Calculates the normal vector between two 2D floating-point vectors.
- `static Uniti::Render::Vector3f getNormal(const Uniti::Render::Vector3f &base, const Uniti::Render::Vector3f &direction)`: Calculates the normal vector between two 3D floating-point vectors.
