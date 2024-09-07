//
// Created by stormblessed on 9/6/24.
//

#pragma once

#ifndef NOOK_RESOURCEMANAGER_H
#define NOOK_RESOURCEMANAGER_H

#include <string>
#include <unordered_map>
#include <memory>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

namespace NOOK {

    class ResourceManager {
    public:
        void init();
        void loadTextures();
        void loadSounds();
        void loadFonts();
        std::string m_assetsPath;
        std::string m_textureDirectory;
        std::string m_soundsDirectory;
        std::string m_fontsDirectory;
        std::shared_ptr<sf::Font> getFont(const std::string& font);
    private:
        std::shared_ptr<sf::Texture> loadTexture(const std::string& path);
        std::shared_ptr<sf::SoundBuffer> loadSound(const std::string& path);
        std::shared_ptr<sf::Font> loadFont(const std::string& path);
        std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_textures;
        std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> m_sounds;
        std::unordered_map<std::string, std::shared_ptr<sf::Font>> m_fonts;
    };

} // NAMESPACE NOOK

#endif //NOOK_RESOURCEMANAGER_H
