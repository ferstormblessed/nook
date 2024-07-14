//
// Created by stormblessed on 7/14/24.
//

#include "GameLoopManager.h"
#include "imgui-SFML.h"
#include <iostream>

GameLoopManager* GameLoopManager::m_instance = nullptr;

GameLoopManager& GameLoopManager::getInstance() {
    std::cout << "Getting instance of GameLoopManager" << std::endl;
    if (m_instance == nullptr) {
        std::cout << "m_instance is nullptr" << std::endl;
        m_instance = new GameLoopManager{};
        std::cout << "memory address is = " << m_instance << std::endl;
        return *m_instance;
    }

    std::cout << "returning previously existing instance" << std::endl;
    std::cout << "memory address is = " << m_instance << std::endl;
    return *m_instance;
}

void GameLoopManager::init(sf::RenderWindow &window,
                           const std::function<void()> &updateCallback,
                           const std::function<void()> &drawCallback) {
    std::cout << "initializing GameLoopManager" << std::endl;
    m_window = &window;
    m_updateCallback = updateCallback;
    m_drawCallback = drawCallback;
}

void GameLoopManager::startUp() {
    std::cout << "starting up GameLoopManager" << std::endl;
}

void GameLoopManager::shutDown() {
    std::cout << "shutting down GameLoopManager" << std::endl;
}

void GameLoopManager::run() {
    if (!m_updateCallback || !m_drawCallback) {
        // Handle error: callbacks not set
        std::cerr << "Error: Game loop callbacks not initialized!" << std::endl;
        return;
    }

    while (m_running) {
        std::cout << "inside main Game Loop" << std::endl;
        handleEvents();
    }
    std::cout << "run = false" << std::endl;
    std::cout << "exiting game loop" << std::endl;
}

void GameLoopManager::handleEvents() {
    std::cout << "Handling events" << std::endl;

    if (!ImGui::SFML::Init(*m_window)) {
        std::cout << "return because of imgui::sfml::init" << std::endl;
        return;
    }

    while (m_window->isOpen()) {
        std::cout << "inside handle events while loop" << std::endl;
        sf::Event event{};
        while (m_window->pollEvent(event)) {
            ImGui::SFML::ProcessEvent(*m_window, event);

            if (event.type == sf::Event::Closed) {
                m_running = false;
                m_window->close();
            }
        }

        ImGui::SFML::Update(*m_window, m_deltaClock.restart());

        //m_updateCallback(elapsedTime.asSeconds()); // Pass elapsed time for smooth updates
        m_updateCallback();
        m_drawCallback();

        ImGui::SFML::Render(*m_window);
        m_window->display();
    }

    ImGui::SFML::Shutdown();
}

GameLoopManager::GameLoopManager() = default;
GameLoopManager::~GameLoopManager() = default;
