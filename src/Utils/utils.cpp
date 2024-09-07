//
// Created by stormblessed on 9/5/24.
//

#include "utils.h"
#include <dirent.h>
#include <filesystem>
#include "spdlog/spdlog.h"
#include <fstream>
#include <sstream>

namespace NOOK {

    std::vector<std::string> getFilesInDirectory(const std::string &directoryPath) {
        std::vector<std::string> files;

        DIR *dir;
        dir = opendir(directoryPath.c_str());
        if (dir == nullptr) {
            spdlog::error("Error opening directory: {}", directoryPath);
            return files;
        }

        struct dirent *entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_type == DT_REG) { // Check if it's a regular file
                std::string filePath = directoryPath + "/" + entry->d_name;
                files.push_back(filePath);
            }
        }

        closedir(dir);
        return files;
    }

    std::string getFileNameWithoutExtension(const std::string &filePath) {
        std::filesystem::path path(filePath);
        return path.stem().string();
    }

    Config loadConfigFromFile(const std::string& filename) {
        Config config;

        std::ifstream configFile(filename);
        if (!configFile.is_open()) {
            spdlog::error("Error opening config file");
            return config;
        }

        std::string line;
        while (std::getline(configFile, line)) {
            std::istringstream iss(line);
            std::string key, value;
            if (std::getline(iss, key, '=') && std::getline(iss, value)) {
                if (key == "WINDOW_TITLE") {
                    config.WINDOW_TITLE = value;
                } else if (key == "WIDTH") {
                    config.WIDTH = std::stoi(value);
                } else if (key == "HEIGHT") {
                    config.HEIGHT = std::stoi(value);
                } else if (key == "FRAMES") {
                    config.FRAMES = std::stoi(value);
                } else if (key == "ASSETS_PATH") {
                    config.ASSETS_PATH = value;
                } else if (key == "AUDIO_DIRECTORY") {
                    config.AUDIO_DIRECTORY = value;
                } else if (key == "FONTS_DIRECTORY") {
                    config.FONTS_DIRECTORY = value;
                } else if (key == "SPRITES_DIRECTORY") {
                    config.SPRITES_DIRECTORY = value;
                }
            }
        }

        configFile.close();
        return config;
    }

}