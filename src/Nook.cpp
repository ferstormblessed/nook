//
// Created by stormblessed on 7/13/24.
//

#include "Nook.h"
#include "spdlog/spdlog.h"

Nook* Nook::s_instance = nullptr;

Nook& Nook::getInstance() {
    spdlog::info("Getting instance of Nook");
    if (s_instance == nullptr) {
        spdlog::info("s_instance is nullptr");
        spdlog::info("Creating new Nook instance");
        s_instance = new Nook{};
        return *s_instance;
    }
    spdlog::info("Returning previously existing instance of Nook");
    return *s_instance;
}

void Nook::startUp() {
    spdlog::info("Starting up Nook");

    // initialization of managers
    m_inputManager = &InputManager::getInstance();
    m_gameLoopManager = &GameLoopManager::getInstance();


    // window
    sf::RenderWindow window(sf::VideoMode(800,600), "nook");
    window.setFramerateLimit(30);

    // Game Loop
    m_gameLoopManager->startUp(&window, m_inputManager);
    m_gameLoopManager->run();

    // shutting down manager
    m_gameLoopManager->shutDown();
    m_inputManager->shutDown();
}

void Nook::shutDown() {
    spdlog::info("Shutting down Nook");
    m_gameLoopManager = nullptr;
    m_inputManager = nullptr;
}

Nook::Nook() = default;
Nook::~Nook() = default;
