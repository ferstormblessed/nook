//
// Created by stormblessed on 9/5/24.
//

#pragma once

#ifndef NOOK_UTILS_H
#define NOOK_UTILS_H

#include <vector>
#include <string>

namespace NOOK {

    std::vector<std::string> getFilesInDirectory(const std::string& directoryPath);
    std::string getFileNameWithoutExtension(const std::string& filePath);

} // NAMESPACE NOOK

#endif //NOOK_UTILS_H
