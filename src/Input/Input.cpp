//
// Created by stormblessed on 9/4/24.
//

#include "Input.h"
#include "spdlog/spdlog.h"
#include "SFML/Graphics/RenderWindow.hpp"

void NOOK::Input::init() {
    spdlog::info("initializing INPUT SYSTEM");
}

bool NOOK::Input::isKeyDown(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

bool NOOK::Input::isMouseButtonDown(sf::Mouse::Button button) {
    return sf::Mouse::isButtonPressed(button);
}

void NOOK::Input::update(const sf::Event &event) {

}

sf::Vector2i NOOK::Input::getMousePosition(sf::RenderWindow& window) {
    return sf::Mouse::getPosition(window);
}
