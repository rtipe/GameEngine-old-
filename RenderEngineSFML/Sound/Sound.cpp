//
// Created by youba on 05/10/2023.
//

#include "Sound.hpp"


namespace Uniti::Render {
    bool Sound::playSound(const std::string &name, float volume) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        if (!this->_sounds.contains(name))
            return false;
        this->_sounds[name].setVolume(volume);
        this->_sounds[name].play();
        return true;
    }

    bool Sound::playMusic(const std::string &name, float volume, bool loop) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        if (!this->_musics.contains(name))
            return false;
        this->_musics[name]->setVolume(volume);
        this->_musics[name]->setLoop(loop);
        this->_musics[name]->play();
        return true;
    }

    bool Sound::pause(const std::string &name) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        if (this->_sounds.contains(name)) {
            this->_sounds[name].pause();
            return true;
        }
        if (this->_musics.contains(name)) {
            this->_musics[name]->pause();
            return true;
        }
        return false;
    }

    bool Sound::reset(const std::string &name) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        if (this->_sounds.contains(name)) {
            this->_sounds[name].stop();
            return true;
        }
        if (this->_musics.contains(name)) {
            this->_musics[name]->stop();
            return true;
        }
        return false;
    }

    bool Sound::changeVolume(const std::string &name, float volume) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        if (this->_sounds.contains(name)) {
            this->_sounds[name].setVolume(volume);
            return true;
        }
        if (this->_musics.contains(name)) {
            this->_musics[name]->setVolume(volume);
            return true;
        }
        return false;
    }

    Sound::SoundStatus Sound::getStatus(const std::string &name) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        if (this->_sounds.contains(name)) {
            sf::SoundSource::Status status = this->_sounds[name].getStatus();
            switch (status) {
                case sf::SoundSource::Stopped:
                    return PAUSE;
                case sf::SoundSource::Playing:
                    return RESUME;
                case sf::SoundSource::Paused:
                    return PAUSE;
                default:
                    return UNDEFINED;
            }
        }
        if (this->_musics.contains(name)) {
            sf::SoundSource::Status status = this->_musics[name]->getStatus();
            switch (status) {
                case sf::SoundSource::Stopped:
                    return PAUSE;
                case sf::SoundSource::Playing:
                    return RESUME;
                case sf::SoundSource::Paused:
                    return PAUSE;
                default:
                    return UNDEFINED;
            }
        }
        return UNDEFINED;
    }

    bool Sound::addSound(const Json::Value &value) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        if (!value.isMember("path") || !value.isMember("name"))
            return false;
        if (!value["path"].isString() || !value["name"].isString())
            return false;
        const std::string &path = value["path"].asString();
        const std::string &name = value["name"].asString();
        return this->addSound(name, path);
    }

    bool Sound::addSound(const std::string &name, const std::string &path) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_soundsBuffer[name] = sf::SoundBuffer();
        this->_sounds[name] = sf::Sound();
        if (!this->_soundsBuffer[name].loadFromFile(path))
            return false;
        this->_sounds[name].setBuffer(this->_soundsBuffer[name]);
        return true;
    }

    bool Sound::addMusic(const Json::Value &value) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        if (!value.isMember("path") || !value.isMember("name"))
            return false;
        if (!value["path"].isString() || !value["name"].isString())
            return false;
        const std::string &path = value["path"].asString();
        const std::string &name = value["name"].asString();
        return this->addMusic(name, path);
    }

    bool Sound::addMusic(const std::string &name, const std::string &path) {
        const std::lock_guard<std::mutex> lock(this->_mutex);
        this->_musics[name] = std::make_unique<sf::Music>();
        if (!this->_musics[name]->openFromFile(path))
            return false;
        return true;
    }
}