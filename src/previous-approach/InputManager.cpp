//
// Created by stormblessed on 7/15/24.
//

#include "InputManager.h"
#include "spdlog/spdlog.h"
#include "SFML/Graphics.hpp"
#include "imgui-SFML.h"

void InputManager::startUp() {
    spdlog::info("Starting up InputManager");
    m_data = Data::getInstance();
}

void InputManager::processInput() {
    spdlog::debug("Processing input through InputManager");
    sf::Event event{};
    while (m_data->getWindow()->pollEvent(event)) {
        ImGui::SFML::ProcessEvent(*m_data->getWindow(), event);

        if (event.type == sf::Event::Closed) {
            m_data->getWindow()->close();
        }
        if (event.type == sf::Event::KeyPressed && sf::Keyboard::Key::Escape == event.key.code) {
            m_data->getWindow()->close();
        }
    }
}

bool InputManager::isKeyPressed(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

void InputManager::shutDown() {
    spdlog::info("Shutting down InputManager");
}

InputManager::InputManager() {
    spdlog::warn("INPUTMANAGER CREATED");
}
InputManager::~InputManager() {
    spdlog::warn("INPUTMANAGER DESTROYED");
}
