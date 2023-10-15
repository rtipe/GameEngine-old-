# Readme

## Description

This is a C++ class called `AssetManager` designed for managing assets in a game. It provides functionalities to load, access, add, and remove textures and fonts. The class uses JSON input to specify the assets to be loaded.

## Usage

### Constructor

AssetManager(const Json::Value &assets);

- Constructs an `AssetManager` object with the specified JSON value containing asset information.

### Loading Assets

void loadAssets(const Json::Value &assets);

- Loads assets from the provided JSON value.

### Getting Fonts

const Render::Font &getFont(const std::string &name) const;
Render::Font &getFont(const std::string &name);

- Returns a reference to the specified font.

### Getting Textures

const Render::Texture &getTexture(const std::string &name) const;
Render::Texture &getTexture(const std::string &name);

- Returns a reference to the specified texture.

### Adding Textures

void addTexture(const Json::Value &params);
void addTexture(const std::string &path, const std::string &name, bool isSmooth = false, bool isRepeated = false);
void addTexture(std::unique_ptr<Render::Texture> texture, const std::string &name);

- Adds a texture with specified parameters.

### Adding Fonts

void addFont(const Json::Value &params);
void addFont(const std::string &path, const std::string &name);

- Adds a font with specified parameters.

### Removing Textures and Fonts

bool removeTexture(const std::string &name);
bool removeFont(const std::string &name);

- Removes the specified texture or font.

### Clearing Textures and Fonts

void clearTextures();
void clearFonts();

- Clears all textures or fonts.
