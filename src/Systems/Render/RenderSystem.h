//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_RENDERSYSTEM_H
#define NOOK_RENDERSYSTEM_H

#include <memory>
#include "../../core/System.h"
#include "../../components/Sprite.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../components/Transform.h"
#include "../../components/Shape.h"
#include "../../components/CircleShape.h"

namespace NOOK {

    class RenderSystem : public System {
    public:
        void init();
        void update(sf::RenderWindow* window);
    private:
        void drawShape(sf::RenderWindow& window, const NOOK::Entity& entity);
        void drawCircleShape(sf::RenderWindow& window, const NOOK::Entity& entity, NOOK::Shape& shape);
        void drawRectangleShape(sf::RenderWindow& window, const NOOK::Entity& entity);
        void drawLineShape(sf::RenderWindow& window, const NOOK::Entity& entity);
        void initSprite(NOOK::Sprite& sprite);
    };

} // NAMESPACE NOOK


#endif //NOOK_RENDERSYSTEM_H
