//
// Created by stormblessed on 9/5/24.
//

#include "RenderTextSystem.h"
#include "../../core/Coordinator.h"
#include "../../components/Text.h"
#include "SFML/Graphics/Text.hpp"
#include "../../core/ResourceManager.h"

// TODO: add transform component management

extern NOOK::Coordinator gCoordinator;
extern NOOK::ResourceManager resourceManager;

void NOOK::RenderTextSystem::init() {
    spdlog::info("initializing RENDER TEXT SYSTEM");
}

void NOOK::RenderTextSystem::update(sf::RenderWindow* window) {
    for (auto& entity : m_entities) {
        renderText(*window, entity);
    }
}

void NOOK::RenderTextSystem::renderText(sf::RenderWindow& window, const NOOK::Entity& entity) {
    // TODO: should set an init function, so i don't do the creation every cycle and function to see when something changes
    auto& text = gCoordinator.getComponent<NOOK::Text>(entity);

    if (text.font.empty()) {
        spdlog::error("Provide a font name");
        return;
    }

    if (text.size < 1) {
        spdlog::error("Invalid size for text");
        return;
    }

    if (resourceManager.getFont(text.font) == nullptr) {
        spdlog::error("Unable to get font: {}", text.font);
        return;
    }

    sf::Text newText;
    newText.setFont(*resourceManager.getFont(text.font));
    newText.setString(text.text);
    newText.setCharacterSize(text.size);
    newText.setFillColor(text.color);
    newText.setOutlineColor(text.outlineColor);
    newText.setOutlineThickness(text.outlineThickness);
    newText.setLineSpacing(text.lineSpacing);
    newText.setLetterSpacing(text.letterSpacing);

    if (text.isBold) {
        newText.setStyle(newText.getStyle() | sf::Text::Bold);
    }
    if (text.isItalic) {
        newText.setStyle(newText.getStyle() | sf::Text::Italic);
    }
    if (text.isUnderlined) {
        newText.setStyle(newText.getStyle() | sf::Text::Underlined);
    }
    if (text.isStrikeThrough) {
        newText.setStyle(newText.getStyle() | sf::Text::StrikeThrough);
    }

    window.draw(newText);
}
