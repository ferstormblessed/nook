//
// Created by stormblessed on 9/5/24.
//

#include <iostream>
#include "NOOK/core/Coordinator.h"
#include "NOOK/core/ResourceManager.h"
#include "NOOK/Systems/Render/RenderTextSystem.h"
#include "NOOK/components/Text.h"
#include "NOOK/components/Transform.h"
#include "SFML/Graphics/Text.hpp"

extern NOOK::Coordinator gCoordinator;
extern NOOK::ResourceManager resourceManager;

void NOOK::RenderTextSystem::init() {
    std::cout << "INFO: initializing RENDER TEXT SYSTEM" << std::endl;
}

void NOOK::RenderTextSystem::update(sf::RenderWindow* window) {
    for (auto& entity : m_entities) {
        renderText(*window, entity);
    }
}

void NOOK::RenderTextSystem::renderText(sf::RenderWindow& window, const NOOK::Entity& entity) {
    // TODO: should set an init function, so i don't do the creation every cycle and function to see when something changes
    auto& text = gCoordinator.getComponent<NOOK::Text>(entity);
    auto& transform = gCoordinator.getComponent<NOOK::Transform>(entity);

    if (text.font->empty()) {
        std::cerr << "ERROR: Provide a font name" << std::endl;
        return;
    }

    if (*text.size < 1) {
        std::cerr << "ERROR: Invalid size for text" << std::endl;
        return;
    }

    if (resourceManager.getFont(*text.font) == nullptr) {
        std::cerr << "ERROR: Unable to get font: " << *text.font << std::endl;
        return;
    }

    sf::Text newText;
    newText.setFont(*resourceManager.getFont(*text.font));
    newText.setString(*text.text);
    newText.setCharacterSize(*text.size);
    newText.setFillColor(text.color);
    newText.setOutlineColor(text.outlineColor);
    newText.setOutlineThickness(*text.outlineThickness);
    newText.setLineSpacing(*text.lineSpacing);
    newText.setLetterSpacing(*text.letterSpacing);
    newText.setPosition(transform.position.x, transform.position.y);

    if (*text.isBold) {
        newText.setStyle(newText.getStyle() | sf::Text::Bold);
    }
    if (*text.isItalic) {
        newText.setStyle(newText.getStyle() | sf::Text::Italic);
    }
    if (*text.isUnderlined) {
        newText.setStyle(newText.getStyle() | sf::Text::Underlined);
    }
    if (*text.isStrikeThrough) {
        newText.setStyle(newText.getStyle() | sf::Text::StrikeThrough);
    }

    window.draw(newText);
}
