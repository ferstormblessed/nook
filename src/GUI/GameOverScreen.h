//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_GAMEOVERSCREEN_H
#define NOOK_GAMEOVERSCREEN_H

#include <functional>
#include "imgui.h"
#include "../core/Types.h"
#include "../components/GameOver.h"

namespace NOOK {

    void GameOverScreen(NOOK::GameOver& gameOverComponent) {
        // Create a full-screen ImGui window
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize); // Cover entire screen

        // No title bar, resize, or move options for a full overlay effect
        ImGui::Begin("Game Over Screen", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);

        // Center "Game Over" text
        ImGui::SetCursorPosY(ImGui::GetWindowHeight() / 3);
        ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("Game Over").x) / 2);
        ImGui::Text("Game Over");

        // Center "Play Again" button below the text
        ImGui::SetCursorPosY(ImGui::GetWindowHeight() / 2);
        ImGui::SetCursorPosX((ImGui::GetWindowWidth() - 200) / 2);  // Adjust width for the button
        if (ImGui::Button("Play Again", ImVec2(200, 50))) {
            gameOverComponent.isOver = false;
            gameOverComponent.playAgain = true;
        }

        ImGui::End();
    }

} // NAMESPACE NOOK

#endif //NOOK_GAMEOVERSCREEN_H
