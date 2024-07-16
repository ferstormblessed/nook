//
// Created by stormblessed on 7/15/24.
//

#include "InputManager.h"
#include "spdlog/spdlog.h"
#include <SFML/Graphics.hpp>

InputManager* InputManager::s_instance = nullptr;

InputManager &InputManager::getInstance() {
    if (s_instance == nullptr) {
        spdlog::info("s_instance is nullptr");
        spdlog::info("Creating new Nook instance");
        s_instance = new InputManager{};
        return *s_instance;
    }
    spdlog::info("Returning previously existing instance of Nook");
    return *s_instance;
}

void InputManager::startUp(sf::RenderWindow* window) {
    spdlog::info("Starting up InputManager");
    m_window = window;
}

void InputManager::processInput() {
    spdlog::info("Processing input through InputManager");
}

bool InputManager::isKeyPressed(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

void InputManager::shutDown() {
    spdlog::info("Shutting down InputManager");
}

InputManager::InputManager() = default;
InputManager::~InputManager() = default;
