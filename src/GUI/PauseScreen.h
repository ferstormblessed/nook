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
        float windowWidth = ImGui::GetIO().DisplaySize.x;
        float windowHeight = ImGui::GetIO().DisplaySize.y;
        ImGui::SetNextWindowPos(ImVec2(windowWidth / 4, windowHeight / 4)); // Position to center a half-screen
        ImGui::SetNextWindowSize(ImVec2(windowWidth / 2, windowHeight / 2)); // Half-size the screen dimensions

        // No title bar, resize, or move options for a full overlay effect
        ImGui::Begin("PAUSE", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);

        // Center pause text
        ImGui::SetCursorPosY(ImGui::GetWindowHeight() / 2 - ImGui::CalcTextSize("PAUSE").y);
        ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("PAUSE").x) / 2);
        ImGui::Text("PAUSE");

        // Hint text
        std::string message = "Press the key " + key + " to unpause";
        ImGui::SetCursorPosY(3 * ImGui::GetWindowHeight() / 4);
        ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize(message.c_str()).x) / 2);
        ImGui::Text("%s", message.c_str());

        ImGui::End();
    }

} // NAMESPACE NOOK

#endif //NOOK_PAUSESCREEN_H
