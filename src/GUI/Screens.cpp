//
// Created by stormblessed on 10/29/24.
//

#include "NOOK/GUI/Screens.h"
#include "imgui.h"

namespace NOOK {

    void FloatVariableDebugGUI(const std::string &variableName, float *variableValue) {
        std::string windowTitle = variableName + " - Debug";
        ImGui::SetNextWindowSize(ImVec2(400, 300), ImGuiCond_FirstUseEver);  // Set initial window size

        ImGui::Begin(windowTitle.c_str());
        // Display the variable name and its value side by side
        ImGui::Text("%s: ", variableName.c_str());
        ImGui::SameLine();
        ImGui::InputFloat(("##" + variableName).c_str(), variableValue, 0.1f, 1.0f, "%.3f");
        ImGui::End();
    }

    void GameOverScreen(NOOK::GameOver &gameOverComponent) {
        // Create a full-screen ImGui window
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize); // Cover entire screen

        // No title bar, resize, or move options for a full overlay effect
        ImGui::Begin("Game Over Screen", nullptr,
                     ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                     ImGuiWindowFlags_NoScrollbar);

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

    void IntVariableDebugGUI(const std::string &variableName, int *variableValue) {
        std::string windowTitle = variableName + " - Debug";
        ImGui::SetNextWindowSize(ImVec2(400, 300), ImGuiCond_FirstUseEver);  // Set initial window size

        ImGui::Begin(windowTitle.c_str());
        // Display the variable name and its value side by side
        ImGui::Text("%s: ", variableName.c_str());
        ImGui::SameLine();
        ImGui::InputInt(("##" + variableName).c_str(), variableValue, 1, 10);

        ImGui::End();
    }

    void PauseScreen(const std::string &key) {
        float windowWidth = ImGui::GetIO().DisplaySize.x;
        float windowHeight = ImGui::GetIO().DisplaySize.y;
        ImGui::SetNextWindowPos(ImVec2(windowWidth / 4, windowHeight / 4)); // Position to center a half-screen
        ImGui::SetNextWindowSize(ImVec2(windowWidth / 2, windowHeight / 2)); // Half-size the screen dimensions

        // No title bar, resize, or move options for a full overlay effect
        ImGui::Begin("PAUSE", nullptr,
                     ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                     ImGuiWindowFlags_NoScrollbar);

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
}