//
// Created by stormblessed on 9/5/24.
//

#ifndef NOOK_RENDERSHAPESYSTEM_H
#define NOOK_RENDERSHAPESYSTEM_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "NOOK/components/Shape.h"
#include "NOOK/components/CircleShape.h"
#include "NOOK/components/RectangleShape.h"

namespace NOOK {

    class RenderShapeSystem : public System {
    public:
        void init();
        void update(sf::RenderWindow* window);
    private:
        void drawShape(sf::RenderWindow& window, const NOOK::Entity& entity);
        void drawCircleShape(sf::RenderWindow& window, const NOOK::Entity& entity, NOOK::Shape& shape);
        void drawRectangleShape(sf::RenderWindow& window, const NOOK::Entity& entity, NOOK::Shape& shape);

        void initCircleShape(const NOOK::Entity &entity, NOOK::Shape &shape, NOOK::CircleShape& circleShape);
        void initRectangleShape(const NOOK::Entity &entity, NOOK::Shape &shape, NOOK::RectangleShape& rectangleShape);
    };

} // NAMESPACE NOOK


#endif //NOOK_RENDERSHAPESYSTEM_H
