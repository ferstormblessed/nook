//
// Created by stormblessed on 9/6/24.
//

#include "ResourceManager.h"
#include "spdlog/spdlog.h"
#include "../Utils/utils.h"

void NOOK::ResourceManager::init() {
    spdlog::info("initializing RESOURCE MANAGER");
    loadTextures();
    loadSounds();
    loadFonts();
}

void NOOK::ResourceManager::loadTextures() {
    spdlog::info("loading TEXTURES");
    std::vector<std::string> spriteFiles = NOOK::getFilesInDirectory(m_assetsPath+m_textureDirectory);

    for (auto& file : spriteFiles) {
        std::string spriteName = NOOK::getFileNameWithoutExtension(file);
        std::shared_ptr<sf::Texture> texture = loadTexture(file);
        m_textures[spriteName] = texture;
    }
}

void NOOK::ResourceManager::loadSounds() {
    spdlog::info("loading AUDIOS");
    std::vector<std::string> files = NOOK::getFilesInDirectory(m_assetsPath+m_soundsDirectory);

    for (auto& file : files) {
        std::string soundName = NOOK::getFileNameWithoutExtension(file);
        std::shared_ptr<sf::SoundBuffer> sound = loadSound(file);
        m_sounds[soundName] = sound;
    }
}

void NOOK::ResourceManager::loadFonts() {
    spdlog::info("loading FONTS");
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
        spdlog::error("Failed to load texture from file: {}", path);
    }
    if (!texture->generateMipmap()) {
        spdlog::error("Failed to generate MipMap for texture of file: {}", path);
    }
    return texture;
}

std::shared_ptr<sf::SoundBuffer> NOOK::ResourceManager::loadSound(const std::string &path) {
    auto sound = std::make_shared<sf::SoundBuffer>();
    if (!sound->loadFromFile(path)) {
        spdlog::error("Failed to load sound from file: {}", path);
    }
    return sound;
}

std::shared_ptr<sf::Font> NOOK::ResourceManager::loadFont(const std::string &path) {
    auto font = std::make_shared<sf::Font>();
    if (!font->loadFromFile(path)) {
        spdlog::error("Failed to load font from file: {}", path);
    }
    return font;
}

std::shared_ptr<sf::Font> NOOK::ResourceManager::getFont(const std::string& font) {
    if (m_fonts.count(font) == 0) {
        spdlog::error("Not a valid font name: {}", font);
        return nullptr;
    }
    return m_fonts.at(font);
}

std::shared_ptr<sf::Texture> NOOK::ResourceManager::getTexture(const std::string &texture) {
    if (m_textures.count(texture) == 0) {
        spdlog::error("Not a valid texture name: {}", texture);
        return nullptr;
    }
    return m_textures.at(texture);
}

