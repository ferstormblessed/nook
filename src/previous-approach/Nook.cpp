//
// Created by stormblessed on 7/13/24.
//

#include "Nook.h"
#include "SFML/Graphics.hpp"
#include "InputManager.h"
#include "GameLoopManager.h"
#include "spdlog/spdlog.h"

void Nook::startUp() {
    spdlog::info("Starting up Nook");

    // window
    sf::RenderWindow window(sf::VideoMode(800,600), "nook");
    window.setFramerateLimit(30);

    // Data singleton
    m_data = Data::getInstance();
    m_data->starUp(&window);

    // Creation of Managers
    InputManager inputManager{};
    GameLoopManager gameLoopManager{};

    // Initialization of Managers
    inputManager.startUp(&window);
    gameLoopManager.startUp(&window, &inputManager);

    // Game Loop
    gameLoopManager.run();

    // shutting down manager
    gameLoopManager.shutDown();
    inputManager.shutDown();

    m_data->shutDown();
}

void Nook::shutDown() {
    spdlog::info("Shutting down Nook");
    delete &m_data;
}

Nook::Nook() {
    spdlog::warn("NOOK CREATED");
}
Nook::~Nook() {
    spdlog::warn("NOOK DESTROYED");
}
