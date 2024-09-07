//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_RENDERSPRITESYSTEM_H
#define NOOK_RENDERSPRITESYSTEM_H

#include <memory>
#include <unordered_map>
#include "../../core/System.h"
#include "../../components/Sprite.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../components/Shape.h"

namespace NOOK {

    class RenderSpriteSystem : public System {
    public:
        void init();
        void update(sf::RenderWindow* window);
    private:
        void renderSprite(sf::RenderWindow& window, const NOOK::Entity& entity);
    };

} // NAMESPACE NOOK


#endif //NOOK_RENDERSPRITESYSTEM_H
