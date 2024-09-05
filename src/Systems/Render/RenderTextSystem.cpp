//
// Created by stormblessed on 9/5/24.
//

#include "RenderTextSystem.h"
#include "../../core/Coordinator.h"
#include "../../utils/utils.h"
#include "../../components/Text.h"
#include "SFML/Graphics/Text.hpp"

// TODO: add transform component management

extern NOOK::Coordinator gCoordinator;

void NOOK::RenderTextSystem::init(const std::string& path) {
    spdlog::info("initializing RENDER TEXT SYSTEM");
    loadFonts(path);
}

void NOOK::RenderTextSystem::update(sf::RenderWindow* window) {
    for (auto& entity : m_entities) {
        renderText(*window, entity);
    }
}

void NOOK::RenderTextSystem::renderText(sf::RenderWindow& window, const NOOK::Entity& entity) {
    auto& text = gCoordinator.getComponent<NOOK::Text>(entity);

    if (text.font.empty()) {
        spdlog::error("Provide a font name");
        return;
    }
    setCurrentFont(text.font);

    if (text.size < 1) {
        spdlog::error("Invalid size for text");
        return;
    }

    // TODO: check problems with map, use contains
    sf::Text newText;
    newText.setFont(currentFont);
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

void NOOK::RenderTextSystem::loadFonts(const std::string &directory) {
    std::vector<std::string> files = NOOK::getFilesInDirectory(directory);

    for (auto& file : files) {
        std::string fontName = NOOK::getFileNameWithoutExtension(file);
        sf::Font font;
        font.loadFromFile(file);
        fontsLibrary[fontName] = font;
    }
}

void NOOK::RenderTextSystem::setCurrentFont(const std::string& font) {
    currentFont = fontsLibrary[font];
}
