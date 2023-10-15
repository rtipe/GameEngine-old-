## Class Movement

The `Movement` class, defined within the `Uniti::Game` namespace, handles the movement functionalities of an object in a 2D or 3D space. It allows the object to move to specific positions, change direction, and control its speed. This class provides essential methods for controlling the motion behavior of an object within a game or graphical application.

### Constructors

- **`Movement(Object &object)`**: Constructor initializing the `Movement` object with a reference to the associated `Object` instance.

### Public Methods

- **`void moveTo(const Render::Vector2f &position, float speed)`**: Moves the object to the specified `position` with the given `speed`.

- **`void moveForward(float speed)`**: Moves the object forward with the specified `speed`.

- **`void moveBackward(float speed)`**: Moves the object backward with the specified `speed`.

- **`void moveLeft(float speed)`**: Moves the object left with the specified `speed`.

- **`void moveRight(float speed)`**: Moves the object right with the specified `speed`.

- **`void move(const Render::Vector2f &normal, float speed)`**: Moves the object in a specific direction defined by the `normal` vector with the given `speed`.

- **`void cancelMovement()`**: Cancels the current movement, stopping the object.

- **`bool isMoving() const`**: Checks if the object is currently in motion and returns a boolean value accordingly.

- **`float getSpeed() const`**: Retrieves the current speed of the object's movement.

- **`void setSpeed(float speed)`**: Sets the speed of the object's movement to the specified value.

- **`void update()`**: Updates the object's movement, applying the necessary transformations based on the current movement state.

- **`const Render::Clock &getClock() const`**: Returns a constant reference to the `Render::Clock` object associated with the movement.

- **`Render::Clock &getClock()`**: Returns a reference to the `Render::Clock` object associated with the movement, allowing modifications.

### Private Methods

- **`Render::Vector3f getDeltaTime()`**: Calculates and returns the delta time, representing the time difference between the current frame and the previous frame.

### Private Properties

- **`std::mutex _mutex`**: Mutex for handling concurrency and ensuring thread safety.

- **`Object &_object`**: Reference to the associated `Object` instance, enabling interaction with the object's properties.

- **`float _speed = 0`**: Current speed of the object's movement, initialized to 0.

- **`Render::Vector2f _to`**: Target position for movement.

- **`bool _isTo = false`**: Indicates if the object is moving to a specific target position.

- **`Render::Clock _clock`**: Clock object for tracking time, used for calculating delta time.

---

*This documentation provides an overview of the methods and properties of the `Movement` class, offering guidance for developers implementing movement functionalities within the Uniti game engine.*
