## Class Collision

The `Collision` class, part of the `Uniti::Game` namespace, manages collision detection for objects within a 2D or 3D space. It handles various collision scenarios, including checking if a point or a bounding box is inside the collision area, detecting overlaps, and managing collision boxes associated with an object.

### Constructors

- **`Collision(Transform &transform)`**: Constructor initializing the `Collision` object with a reference to the associated `Transform` instance.

- **`Collision(const Json::Value &value, Transform &transform)`**: Constructor creating a `Collision` object based on data from a JSON value and a reference to the associated `Transform` instance.

- **`Collision(const std::vector<Render::Box> &collisions, Transform &transform)`**: Constructor creating a `Collision` object with multiple `Render::Box` instances and a reference to the associated `Transform` instance.

- **`Collision(const Render::Box &box, Transform &transform)`**: Constructor creating a `Collision` object with a single `Render::Box` instance and a reference to the associated `Transform` instance.

### Public Methods

- **`void addBox(const Render::Box &box)`**: Adds a `Render::Box` instance to the collision area, allowing for more complex collision shapes.

- **`const std::vector<Render::Box> &getBox() const`**: Returns the collision boxes associated with the object as a constant reference to a vector of `Render::Box` instances.

- **`std::vector<Render::Box> &getBox()`**: Returns the collision boxes associated with the object as a reference to a vector of `Render::Box` instances, enabling modifications.

- **`bool isInside(const Render::Vector2f &point) const`**: Checks if a 2D point is inside the collision area and returns a boolean value accordingly.

- **`bool isInside(const Render::Box &box, const Render::Vector3f &position) const`**: Checks if a specific `Render::Box` instance at the given position is inside the collision area and returns a boolean value accordingly.

- **`bool isInside(const Object &object) const`**: Checks if another `Object` instance is inside the collision area and returns a boolean value accordingly.

- **`bool isOverlap() const`**: Checks if the object is overlapping with another object and returns a boolean value accordingly.

- **`void setOverlap(bool isOverlap)`**: Sets the overlap status of the object, indicating whether it is currently overlapping with another object or not.

### Private Properties

- **`std::vector<Render::Box> _collisions`**: A collection of `Render::Box` instances representing the collision boxes associated with the object.

- **`std::mutex _mutex`**: Mutex for handling concurrency and ensuring thread safety.

- **`Transform &_transform`**: Reference to the associated `Transform` instance, allowing interaction with the object's transformation properties.

- **`bool _isOverlap = false`**: Indicates whether the object is currently overlapping with another object. Initialized to `false`.

---

*This documentation provides details on the methods and properties of the `Collision` class, assisting developers in implementing collision detection functionalities within the Uniti game engine.*
