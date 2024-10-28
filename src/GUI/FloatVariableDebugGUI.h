//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_FLOATVARIABLEDEBUGGUI_H
#define NOOK_FLOATVARIABLEDEBUGGUI_H

#include <string>
#include "imgui.h"

namespace NOOK {

    void FloatVariableDebugGUI(const std::string& variableName, float* variableValue) {
        std::string windowTitle = variableName + " - Debug";
        ImGui::SetNextWindowSize(ImVec2(400, 300), ImGuiCond_FirstUseEver);  // Set initial window size

        ImGui::Begin(windowTitle.c_str());
        // Display the variable name and its value side by side
        ImGui::Text("%s: ", variableName.c_str());
        ImGui::SameLine();
        ImGui::InputFloat(("##" + variableName).c_str(), variableValue, 0.1f, 1.0f, "%.3f");
        ImGui::End();
    }

} // NAMESPACE NOOK

#endif //NOOK_FLOATVARIABLEDEBUGGUI_H
