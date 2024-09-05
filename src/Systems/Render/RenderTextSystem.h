//
// Created by stormblessed on 9/5/24.
//

#pragma once

#ifndef NOOK_RENDERTEXTSYSTEM_H
#define NOOK_RENDERTEXTSYSTEM_H

#include <unordered_map>
#include "../../core/System.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Font.hpp"

namespace NOOK {

    class RenderTextSystem : public System {
    public:
        void init(const std::string& path);
        void update(sf::RenderWindow* window);
    private:
        void renderText(sf::RenderWindow& window, const NOOK::Entity& entity);
        void loadFonts(const std::string& directory);
        void setCurrentFont(const std::string& font);
        sf::Font currentFont;
        std::unordered_map<std::string, sf::Font> fontsLibrary;
    };

} // NAMESPACE NOOK


#endif //NOOK_RENDERTEXTSYSTEM_H
