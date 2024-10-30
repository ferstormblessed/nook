//
// Created by stormblessed on 10/29/24.
//

#pragma once

#ifndef NOOK_SCREENS_H
#define NOOK_SCREENS_H

#include <string>
#include "NOOK/components/GameOver.h"

namespace NOOK {

    void FloatVariableDebugGUI(const std::string& variableName, float* variableValue);
    void GameOverScreen(NOOK::GameOver& gameOverComponent);
    void IntVariableDebugGUI(const std::string& variableName, int* variableValue);
    void PauseScreen(const std::string& key);

} // NAMESPACE NOOK

#endif //NOOK_SCREENS_H
