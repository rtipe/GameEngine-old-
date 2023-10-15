# Event Class

## Description

The `Input` and `Mouse` classes provide functionality for handling user input events.

## Input Class

### Enums

- `Key`: Represents various keyboard keys.

### Member Functions

- `static void update(Window &window)`: Updates the input events based on the provided window.
- `static bool isPressed(const std::string &key)`: Checks if a specific key is pressed.
- `static bool isPressed(Key key)`: Checks if a specific key is pressed.
- `static bool isReleased(const std::string &key)`: Checks if a specific key is released.
- `static bool isReleased(Key key)`: Checks if a specific key is released.
- `static std::vector<std::string> &getEvents()`: Returns a vector of recorded events.
- `static void clearEvents()`: Clears the recorded events.

## Mouse Class

### Enums

- `KeyMouse`: Represents various mouse buttons (LEFT, RIGHT, MIDDLE).

### Member Functions

- `static void update(Window &window)`: Updates the mouse events based on the provided window.
- `static bool isMousePressed(const std::string &key)`: Checks if a specific mouse button is pressed.
- `static bool isMousePressed(KeyMouse keyMouse)`: Checks if a specific mouse button is pressed.
- `static bool isMouseReleased(const std::string &key)`: Checks if a specific mouse button is released.
- `static bool isMouseReleased(KeyMouse keyMouse)`: Checks if a specific mouse button is released.
- `static Vector2f getPosition(Window &window)`: Returns the current mouse position.
- `static std::vector<std::string> &getEvents()`: Returns a vector of recorded events.
- `static void clearEvents()`: Clears the recorded events.
