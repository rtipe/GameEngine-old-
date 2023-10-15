## Class Transform

The `Transform` class, defined within the `Uniti::Game` namespace, represents the transformation properties of an object in a 2D or 3D space. It encapsulates essential attributes such as `position`, `scale`, `origin`, and `rotation`. Objects of this class enable the manipulation and positioning of graphical entities within a game or graphical application.

### Constructors

- **`Transform()`**: Default constructor creating a new `Transform` object with default values.

- **`Transform(const Transform &transform)`**: Copy constructor creating a new `Transform` object by copying the properties of an existing object.

- **`Transform(const Json::Value &value)`**: Constructor creating a `Transform` object based on data from a JSON value.

### Public Methods

- **`const Render::Vector3f &getPosition() const`**: Returns the `position` of the object as a constant reference to a `Render::Vector3f` object.

- **`Render::Vector3f &getPosition()`**: Returns the `position` of the object as a reference to a `Render::Vector3f` object, allowing modifications.

- **`const Render::Vector2f &getScale() const`**: Returns the `scale` of the object as a constant reference to a `Render::Vector2f` object.

- **`Render::Vector2f &getScale()`**: Returns the `scale` of the object as a reference to a `Render::Vector2f` object, allowing modifications.

- **`const Render::Vector2f &getOrigin() const`**: Returns the `origin` of the object as a constant reference to a `Render::Vector2f` object.

- **`Render::Vector2f &getOrigin()`**: Returns the `origin` of the object as a reference to a `Render::Vector2f` object, allowing modifications.

- **`float getRotation() const`**: Returns the `rotation` angle of the object.

- **`void setRotation(float value)`**: Sets the `rotation` angle of the object to the specified value.

### Private Properties

- **`std::mutex _mutex`**: Mutex for handling concurrency and ensuring thread safety.

- **`Render::Vector3f _position`**: Vector representing the `position` of the object in 3D space.

- **`Render::Vector2f _scale`**: Vector representing the `scale` factors of the object in 2D space.

- **`Render::Vector2f _origin`**: Vector representing the `origin` point of the object in 2D space.

- **`float _rotation = 0`**: Rotation angle of the object in degrees, initialized to 0.

---

*This documentation outlines the properties and methods of the `Transform` class, providing a reference for developers working with transformation functionalities in the Uniti game engine.*
