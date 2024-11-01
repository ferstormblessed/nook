//
// Created by stormblessed on 9/5/24.
//

#pragma once

#ifndef NOOK_RENDERTEXTSYSTEM_H
#define NOOK_RENDERTEXTSYSTEM_H

#include <unordered_map>
#include "SFML/Graphics/RenderWindow.hpp"

namespace NOOK {

    class RenderTextSystem : public System {
    public:
        void init();
        void update(sf::RenderWindow* window);
    private:
        void renderText(sf::RenderWindow& window, const NOOK::Entity& entity);
    };

} // NAMESPACE NOOK


#endif //NOOK_RENDERTEXTSYSTEM_H
