//
// Created by youba on 05/10/2023.
//

#pragma once

#include <string>
#include <json/value.h>
#include <SFML/Audio.hpp>
#include <mutex>

namespace Uniti::Render {
    class Sound {
    public:
        enum SoundStatus {
            RESUME,
            PAUSE,
            UNDEFINED
        };
        bool playSound(const std::string &name, float volume);
        bool playMusic(const std::string &name, float volume, bool loop);
        bool pause(const std::string &name);
        bool reset(const std::string &name);
        bool changeVolume(const std::string &name, float volume);
        SoundStatus getStatus(const std::string &name);
        bool addSound(const Json::Value &value);
        bool addSound(const std::string &name, const std::string &path);
        bool addMusic(const Json::Value &value);
        bool addMusic(const std::string &name, const std::string &path);
    private:
        std::map<std::string, sf::SoundBuffer> _soundsBuffer;
        std::map<std::string, sf::Sound> _sounds;
        std::map<std::string, std::unique_ptr<sf::Music>> _musics;
        std::mutex _mutex;
    };
}
