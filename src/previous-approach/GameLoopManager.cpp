//
// Created by stormblessed on 7/14/24.
//

#include "GameLoopManager.h"
#include "imgui-SFML.h"
#include "spdlog/spdlog.h"
#include "../gui.h"

void GameLoopManager::startUp() {
    spdlog::info("Starting up GameLoopManager");
    m_data = Data::getInstance();
    // initialize ImGui::SFML
    if (!ImGui::SFML::Init(*m_data->getWindow())) {
        spdlog::error("Failed to load window through ImGui::SFML");
        return;
    }
}

void GameLoopManager::update() {
    spdlog::debug("Update method from GameLoopManager");
}

void GameLoopManager::draw() {
    spdlog::debug("Draw method from GameLoopManager");
}

void GameLoopManager::run() {
    spdlog::info("Game Loop starts");

    while (m_data->getRunning()) {

        m_inputManager->processInput();
        update();
        draw();

        handleEvents();
        ImGui::SFML::Update(*m_window, m_deltaClock.restart());
        m_window->clear();
        update();
        draw();
        gui();
        ImGui::SFML::Render(*m_window);
        m_window->display();
        if (!m_window->isOpen()) {
        }
    }
    ImGui::SFML::Shutdown();
    spdlog::info("Exiting game loop");
}

void GameLoopManager::handleEvents() {

}

void GameLoopManager::shutDown() {
    spdlog::info("Shutting down GameLoopManager");
    m_window = nullptr;
    m_running = false;
    m_deltaClock = {};
}

GameLoopManager::GameLoopManager() {
    spdlog::warn("GAMELOOPMANAGER CREATED");
}
GameLoopManager::~GameLoopManager() {
    spdlog::warn("GAMELOOPMANAGER DESTROYED");
}
