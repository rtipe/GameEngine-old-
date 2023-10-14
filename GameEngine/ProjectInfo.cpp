//
// Created by youba on 05/10/2023.
//

#include "ProjectInfo.hpp"

#include <filesystem>
#include <fstream>
#include <string>

namespace Uniti::Game {
ProjectInfo::ProjectInfo(const std::string &projectPath) {
  std::ifstream file(projectPath);
  Json::Value project;
  file >> project;
  Json::Value windowInfos = project["windowInfos"];
  Json::Value network = project["networkInfos"];

  this->data = project;
  this->name = project.get("name", "game").asString();
  this->directoryScenePath = project.get("directoryScenePath", "").asString();
  this->startScene = project.get("startScene", "").asString();
  this->globalScene = project.get("globalScene", "").asString();
  this->title = windowInfos.get("title", "game window").asString();
  this->width = windowInfos.get("width", 1920).asInt();
  this->height = windowInfos.get("height", 1080).asInt();
  this->framerateLimit = windowInfos.get("fps", 60).asInt();
  this->iconPath = windowInfos.get("icon", "").asString();
  this->port = network.get("port", 0).asInt();
  this->latence = network.get("latence", 10).asInt();

  for (const auto &entry : std::filesystem::recursive_directory_iterator(
           this->directoryScenePath)) {
    std::string fullPath = entry.path().string();
    std::string directoryPath, fileType, fileName;
    auto pos = fullPath.find_last_of('/');

    if (pos != std::string::npos) {
      directoryPath = fullPath.substr(0, pos);
      directoryPath += '/';
      auto posFileType = fullPath.find_last_of('.');
      fileType = fullPath.substr(posFileType, fullPath.size());
      if (fileType == ".json") {
        pos += 1;
        fileName = fullPath.substr(pos, posFileType - pos) += ".json";
        directoryPath += fileName;
        this->scenes.push_back(ScenePath(fileName, directoryPath));
      }
    }
  }
}
}  // namespace Uniti::Game