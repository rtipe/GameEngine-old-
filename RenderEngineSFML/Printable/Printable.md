# Text Class

## Description

The `Text` class represents text that can be displayed on a window. It inherits from the `IPrintable` interface.

## Enums

- `TextStyle`: Represents different text styles (BOLD, ITALIC, REGULAR).

## Member Functions

- `Text(Text &text)`: Constructor for creating text by copying another text.
- `Text(Font &font)`: Constructor for creating text with a specified font.
- `void setString(const std::string &value)`: Sets the string content of the text.
- `void setFont(Font &font)`: Sets the font of the text.
- `void setCharacterSize(unsigned int size)`: Sets the character size of the text.
- `void setStyle(TextStyle style)`: Sets the style of the text (BOLD, ITALIC, REGULAR).
- `void setColor(const Color &color)`: Sets the color of the text.
- `void display(Window &window) override`: Displays the text on the provided window.
- `const std::string getString() const`: Returns the string content of the text.
- `const std::string &getTypeName() const override`: Returns the type name of the text.
- `const Vector3f &getPosition() const override`: Returns the position of the text.
- `const Vector2f &getScale() const override`: Returns the scale of the text.
- `const float getRotation() const override`: Returns the rotation angle of the text.
- `void setPosition(const Vector3f &position) override`: Sets the position of the text.
- `void setScale(const Vector2f &scale) override`: Sets the scale of the text.
- `void setRotation(float rotation) override`: Sets the rotation angle of the text.
- `void setOrigin(const Vector2f &origin) override`: Sets the origin of the text.

# Sprite Class

## Description

The `Sprite` class represents an image that can be displayed on a window. It inherits from the `IPrintable` interface.

## Member Functions

- `Sprite(Sprite &sprite)`: Constructor for creating a sprite by copying another sprite.
- `Sprite(Texture &texture)`: Constructor for creating a sprite with a specified texture.
- `void setTexture(Texture &texture)`: Sets the texture of the sprite.
- `void setTextureRect(const Box &rect)`: Sets the texture rectangle of the sprite.
- `void setColor(const Color &color)`: Sets the color of the sprite.
- `void display(Window &window) override`: Displays the sprite on the provided window.
- `const std::string &getTypeName() const override`: Returns the type name of the sprite.
- `const Vector3f &getPosition() const override`: Returns the position of the sprite.
- `const Vector2f &getScale() const override`: Returns the scale of the sprite.
- `const float getRotation() const override`: Returns the rotation angle of the sprite.
- `void setPosition(const Vector3f &position) override`: Sets the position of the sprite.
- `void setScale(const Vector2f &scale) override`: Sets the scale of the sprite.
- `void setRotation(float rotation) override`: Sets the rotation angle of the sprite.
- `void setOrigin(const Vector2f &origin) override`: Sets the origin of the sprite.

# IPrintable Interface

## Description

The `IPrintable` interface defines the common functionalities for printable objects.

## Member Functions

- `virtual ~IPrintable() = default;`: Virtual destructor for `IPrintable`.
- `virtual void display(Uniti::Render::Window &window) = 0;`: Displays the printable object on a window.
- `virtual const std::string &getTypeName() const = 0;`: Returns the type name of the printable object.
- `virtual const Vector3f &getPosition() const = 0;`: Returns the position of the printable object.
- `virtual const Vector2f &getScale() const = 0;`: Returns the scale of the printable object.
- `virtual const float getRotation() const = 0;`: Returns the rotation angle of the printable object.
- `virtual void setPosition(const Vector3f &position) = 0;`: Sets the position of the printable object.
- `virtual void setScale(const Vector2f &scale) = 0;`: Sets the scale of the printable object.
- `virtual void setRotation(float rotation) = 0;`: Sets the rotation angle of the printable object.
- `virtual void setOrigin(const Vector2f &origin) = 0;`: Sets the origin of the printable object.
