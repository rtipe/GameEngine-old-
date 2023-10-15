
# Assets Management Classes

## Font Class

### Description

The `Font` class provides functionality for loading and accessing font assets in a game.

### Constructor

Font(const std::string &path);

- Constructs a `Font` object by loading a font from the specified file path.

### Get Path

const std::string &getPath() const;

- Returns the file path of the loaded font.

### Get Font Asset

sf::Font &getFontAsset();

- Returns a reference to the loaded `sf::Font`.

## Texture Class

### Description

The `Texture` class provides functionality for loading and accessing texture assets in a game.

### Constructor

Texture(const std::string &path);

- Constructs a `Texture` object by loading a texture from the specified file path.

### Set Smooth

void setSmooth(bool smooth);

- Sets the smooth property of the texture.

### Set Repeated

void setRepeated(bool repeated);

- Sets the repeated property of the texture.

### Get Path

const std::string &getPath() const;

- Returns the file path of the loaded texture.

### Is Smooth

bool isSmooth() const;

- Returns `true` if the texture is set to be smoothed.

### Is Repeated

bool isRepeated() const;

- Returns `true` if the texture is set to be repeated.

### Get Texture

sf::Texture &getTexture();

- Returns a reference to the loaded `sf::Texture`.
