//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_INTVARIABLEDEBUGGUI_H
#define NOOK_INTVARIABLEDEBUGGUI_H

#include <string>
#include "imgui.h"

namespace NOOK {

    void IntVariableDebugGUI(const std::string& variableName, int* variableValue) {
        std::string windowTitle = variableName + " - Debug";

        ImGui::Begin(windowTitle.c_str());
        // Display the variable name and its value side by side
        ImGui::Text("%s: ", variableName.c_str());
        ImGui::SameLine();
        ImGui::Text("%d", *variableValue); // Adjust format for specific precision if needed

        ImGui::End();
    }

} // NAMESPACE NOOK

#endif //NOOK_INTVARIABLEDEBUGGUI_H
