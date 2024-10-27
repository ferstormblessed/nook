//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_PAUSESCREEN_H
#define NOOK_PAUSESCREEN_H

#include <string>
#include "imgui.h"

namespace NOOK {

    void PauseScreen(const std::string& key) {
        // Create a full-screen ImGui window
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize); // Cover entire screen

        // No title bar, resize, or move options for a full overlay effect
        ImGui::Begin("PAUSE", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);

        // Center "PAUSE" text
        ImGui::SetCursorPosY(ImGui::GetWindowHeight() / 2);
        ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("PAUSE").x) / 2);
        ImGui::Text("PAUSE");

        // Pause hint
        ImGui::SetCursorPosY(3 * ImGui::GetWindowHeight() / 4);
        ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("Press the key p to unpause").x) / 2);
        std::string message = "Press the key " + key + " to unpause";
        ImGui::Text("%s", message.c_str());

        ImGui::End();
    }

} // NAMESPACE NOOK

#endif //NOOK_PAUSESCREEN_H
