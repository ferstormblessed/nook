//
// Created by stormblessed on 9/5/24.
//

#include "utils.h"
#include <dirent.h>
#include <filesystem>
#include "spdlog/spdlog.h"

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

}