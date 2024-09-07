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
        void init();
        void update(sf::RenderWindow* window);
    private:
        void renderText(sf::RenderWindow& window, const NOOK::Entity& entity);
        void loadFonts(const std::string& directory);
    };

} // NAMESPACE NOOK


#endif //NOOK_RENDERTEXTSYSTEM_H
