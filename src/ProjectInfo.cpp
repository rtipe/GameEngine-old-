//
// Created by youba on 25/09/2023.
//

#include "ProjectInfo.hpp"
#include <filesystem>

const std::string ERROR_GLOBAL_SCENE = "Error: can't find globalScene in projectInfos";
const std::string ERROR_STARTING_SCENE = "Error: can't find startingScene in projectInfos";
const std::string ERROR_SCENE_DIRECTORY_PATH = "Error: can't find scene directory path in projectInfos";

namespace UnitiGameEngine {
    ProjectInfo::ProjectInfo(const Json::Value &project) {
        Json::Value windowInfos = project["windowInfos"];

        this->name = project.get("name", "game").asString();
        this->directoryScenePath = project.get("directoryScenePath", ERROR_SCENE_DIRECTORY_PATH).asString();
        this->startScene = project.get("startScene", ERROR_STARTING_SCENE).asString();
        this->globalScene = project.get("globalScene", ERROR_GLOBAL_SCENE).asString();
        this->titleWindow = windowInfos.get("title", "game window").asString();
        this->width = windowInfos.get("width", 1920).asInt();
        this->height = windowInfos.get("height", 1080).asInt();
        this->framerateLimit = windowInfos.get("fps", 60).asInt();

        for (const auto &entry : std::filesystem::recursive_directory_iterator(".")) {
            std::string fullPath = entry.path().string();
            std::string directoryPath, fileType, fileName;
            auto pos = fullPath.find_last_of('/');

            if (pos != std::string::npos) {
                directoryPath = fullPath.substr(0,pos);
                directoryPath += '/';
                auto posFileType = fullPath.find_last_of('.');
                fileType = fullPath.substr(posFileType, fullPath.size());
                if (fileType == ".json") {
                    pos += 1;
                    fileName = fullPath.substr(pos, posFileType - pos) += ".json";
                    this->scenes.push_back(ScenePath(fileName, directoryPath));
                }
            }
        }
    }
}