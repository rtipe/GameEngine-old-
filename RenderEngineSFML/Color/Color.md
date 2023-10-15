# Color Class

## Description

The `Color` class provides functionality for representing and manipulating colors.

## Constructors

### `Color()`

- Constructs a `Color` object with default values (black color, fully opaque).

### `Color(const Json::Value &value)`

- Constructs a `Color` object using JSON data to specify the RGB values (and optionally, alpha).

### `Color(const Color &color)`

- Constructs a `Color` object as a copy of another `Color` object.

### `Color(int r, int g, int b)`

- Constructs a `Color` object with specified red, green, and blue values (fully opaque).

### `Color(int r, int g, int b, int a)`

- Constructs a `Color` object with specified red, green, blue, and alpha values.

## Member Functions

### `int getR() const`

- Returns the red component of the color.

### `int getG() const`

- Returns the green component of the color.

### `int getB() const`

- Returns the blue component of the color.

### `int getA() const`

- Returns the alpha component of the color.

### `void setR(int value)`

- Sets the red component of the color.

### `void setG(int value)`

- Sets the green component of the color.

### `void setB(int value)`

- Sets the blue component of the color.

### `void setA(int value)`

- Sets the alpha component of the color.

### `void set(int r, int g, int b)`

- Sets all RGB components of the color.

### `void set(int r, int g, int b, int a)`

- Sets all RGB and alpha components of the color.
