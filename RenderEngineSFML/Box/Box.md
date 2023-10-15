# Box Class

## Description

The `Box` class provides functionality for managing rectangular bounding boxes and performing various operations related to them.

## Constructors

### `Box(const Json::Value &value)`

- Constructs a `Box` object using JSON data to specify the position and dimensions.

### `Box(float x, float y, float width, float height)`

- Constructs a `Box` object with specified position (x, y) and dimensions (width, height).

## Member Functions

### `const Vector2f &getPosition() const`

- Returns the position of the `Box` as a `Vector2f`.

### `const Vector2f &getDimension() const`

- Returns the dimensions of the `Box` as a `Vector2f`.

### `void setPosition(const Vector2f &position)`

- Sets the position of the `Box`.

### `void setDimension(const Vector2f &dimension)`

- Sets the dimensions of the `Box`.

### `void setX(float x)`

- Sets the x-coordinate of the position.

### `void setY(float y)`

- Sets the y-coordinate of the position.

### `void setWidth(float width)`

- Sets the width of the `Box`.

### `void setHeight(float height)`

- Sets the height of the `Box`.

### `bool isInside(const Vector2f &point) const`

- Checks if a point is inside the `Box`.

### `bool isInside(const Vector2f &point, const Vector3f &parent) const`

- Checks if a point is inside the `Box` with consideration for a parent position.

### `bool isInside(const Box &box) const`

- Checks if another `Box` is completely inside this `Box`.

### `bool isInside(const Box &box, const Vector3f &parentA, const Vector3f &parentB) const`

- Checks if another `Box` is inside this `Box` considering parent positions.
