//
// Created by stormblessed on 9/6/24.
//

#include <iostream>
#include "NOOK/core/ResourceManager.h"
#include "NOOK/Utils/utils.h"

void NOOK::ResourceManager::init() {
    std::cout << "INFO: initializing RESOURCE MANAGER" << std::endl;
    loadTextures();
    loadSounds();
    loadFonts();
}

void NOOK::ResourceManager::loadTextures() {
    std::cout << "INFO: loading TEXTURES" << std::endl;
    std::vector<std::string> spriteFiles = NOOK::getFilesInDirectory(m_assetsPath+m_textureDirectory);

    for (auto& file : spriteFiles) {
        std::string spriteName = NOOK::getFileNameWithoutExtension(file);
        std::shared_ptr<sf::Texture> texture = loadTexture(file);
        m_textures[spriteName] = texture;
    }
}

void NOOK::ResourceManager::loadSounds() {
    std::cout << "INFO: loading AUDIOS" << std::endl;
    std::vector<std::string> files = NOOK::getFilesInDirectory(m_assetsPath+m_soundsDirectory);

    for (auto& file : files) {
        std::string soundName = NOOK::getFileNameWithoutExtension(file);
        std::shared_ptr<sf::SoundBuffer> sound = loadSound(file);
        m_sounds[soundName] = sound;
    }
}

void NOOK::ResourceManager::loadFonts() {
    std::cout << "INFO: loading FONTS" << std::endl;
    std::vector<std::string> files = NOOK::getFilesInDirectory(m_assetsPath+m_fontsDirectory);

    for (auto& file : files) {
        std::string fontName = NOOK::getFileNameWithoutExtension(file);
        std::shared_ptr<sf::Font> font = loadFont(file);
        m_fonts[fontName] = font;
    }
}

std::shared_ptr<sf::Texture> NOOK::ResourceManager::loadTexture(const std::string &path) {
    auto texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(path)) {
        std::cerr << "ERROR: Failed to load texture from file: " << path << std::endl;
    }
    if (!texture->generateMipmap()) {
        std::cerr << "ERROR: Failed to generate MipMap for texture of file: " << path << std::endl;
    }
    return texture;
}

std::shared_ptr<sf::SoundBuffer> NOOK::ResourceManager::loadSound(const std::string &path) {
    auto sound = std::make_shared<sf::SoundBuffer>();
    if (!sound->loadFromFile(path)) {
        std::cerr << "ERROR: Failed to load sound from file: " << path << std::endl;
    }
    return sound;
}

std::shared_ptr<sf::Font> NOOK::ResourceManager::loadFont(const std::string &path) {
    auto font = std::make_shared<sf::Font>();
    if (!font->loadFromFile(path)) {
        std::cerr << "ERROR: Failed to load font from file: {}" << path << std::endl;
    }
    return font;
}

std::shared_ptr<sf::Font> NOOK::ResourceManager::getFont(const std::string& font) {
    if (m_fonts.count(font) == 0) {
        std::cerr << "ERROR: Not a valid font name: {}" << font << std::endl;
        return nullptr;
    }
    return m_fonts.at(font);
}

std::shared_ptr<sf::Texture> NOOK::ResourceManager::getTexture(const std::string &texture) {
    if (m_textures.count(texture) == 0) {
        std::cerr << "ERROR: Not a valid texture name: {}" << texture << std::endl;
        return nullptr;
    }
    return m_textures.at(texture);
}

