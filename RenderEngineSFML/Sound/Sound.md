# Sound Class

## Description

The `Sound` class handles playing and managing sounds and music. It provides functionality for playing both sounds and music, adjusting their volume, and more.

## Enums

- `SoundStatus`: Represents the status of a sound (RESUME, PAUSE, UNDEFINED).

## Member Functions

- `bool playSound(const std::string &name, float volume)`: Plays a sound with a specified name and volume.
- `bool playMusic(const std::string &name, float volume, bool loop)`: Plays music with a specified name, volume, and looping status.
- `bool pause(const std::string &name)`: Pauses a sound or music with a specified name.
- `bool reset(const std::string &name)`: Stops and resets a sound or music with a specified name.
- `bool changeVolume(const std::string &name, float volume)`: Changes the volume of a sound or music with a specified name.
- `SoundStatus getStatus(const std::string &name)`: Gets the status of a sound or music with a specified name.
- `bool addSound(const Json::Value &value)`: Adds a sound from a JSON value.
- `bool addSound(const std::string &name, const std::string &path)`: Adds a sound with a specified name and file path.
- `bool addMusic(const Json::Value &value)`: Adds music from a JSON value.
- `bool addMusic(const std::string &name, const std::string &path)`: Adds music with a specified name and file path.

## Private Members

- `std::map<std::string, sf::SoundBuffer> _soundsBuffer`: Map of sound buffers.
- `std::map<std::string, sf::Sound> _sounds`: Map of sounds.
- `std::map<std::string, std::unique_ptr<sf::Music>> _musics`: Map of music resources.
- `std::mutex _mutex`: Mutex for thread safety.
