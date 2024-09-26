//
// Created by stormblessed on 9/5/24.
//

#include "utils.h"
#include <filesystem>
#include "spdlog/spdlog.h"
#include <fstream>
#include <sstream>

const extern NOOK::Config config;

namespace NOOK {

    std::vector<std::string> getFilesInDirectory(const std::string &directoryPath) {
        std::vector<std::string> files;

        if (!std::filesystem::exists(directoryPath) || !std::filesystem::is_directory(directoryPath)) {
            spdlog::error("Error opening directory: {}", directoryPath);
            return files;
        }

        for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
            if (entry.is_regular_file()) {
                files.push_back(entry.path().string());
            }
        }

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
                } else if (key == "GRAVITY") {
                    config.GRAVITY = std::stof(value);
                }
            }
        }

        configFile.close();
        return config;
    }

    float xCoordinatePixelToMetric(float pixelValue) {
        return (pixelValue - config.WIDTH / 2) * 0.02f;
    }

    float yCoordinatePixelToMetric(float pixelValue) {
        return (config.HEIGHT / 2 - pixelValue) * 0.02f;
    }

    float xCoordinateMetricToPixel(float metricValue) {
        return (metricValue + config.WIDTH / 2) * 50.0f;
    }
    float yCoordinateMetricToPixel(float metricValue) {
        return (config.HEIGHT / 2 - metricValue ) * 50.0f;
    }

    float pixelToMetric(float pixelValue) {
        return pixelValue * 0.02f;
    }

    float metricToPixel(float metricValue) {
        return metricValue * 50.0f;
    }


} // NAMESPACE NOOK