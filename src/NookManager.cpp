//
// Created by stormblessed on 7/13/24.
//

#include "NookManager.h"
#include <iostream>

NookManager* NookManager::m_instance = nullptr;

NookManager& NookManager::getInstance() {
    std::cout << "Getting instance of NookManager" << std::endl;
    if (m_instance == nullptr) {
        std::cout << "m_instance is nullptr" << std::endl;
        m_instance = new NookManager{};
        std::cout << "memory address is = " << m_instance << std::endl;
        return *m_instance;
    }

    std::cout << "returning previously existing instance" << m_instance << std::endl;
    std::cout << "memory address is = " << m_instance << std::endl;
    return *m_instance;
}

// Implement your update and draw functions here
void updateGame() {
    // Update game logic based on dt (elapsed time)
    std::cout << "update game" << std::endl;
}

void drawGame() {
    // Draw game objects using SFML
    std::cout << "draw game" << std::endl;
}

void NookManager::startUp() {
    std::cout << "starting up NookManager" << std::endl;

    // initialization of managers
    m_gameLoopManager = &GameLoopManager::getInstance();

    // window
    sf::RenderWindow window(sf::VideoMode(800,600), "nook");

    // Game Loop
    m_gameLoopManager->startUp();
    m_gameLoopManager->init(window, updateGame, drawGame);
    m_gameLoopManager->run();

    // shutting down manager
    m_gameLoopManager->shutDown();
}

void NookManager::shutDown() {
    std::cout << "shutting down NookManager" << std::endl;
}

NookManager::NookManager() = default;
NookManager::~NookManager() = default;



