//
// Created by stormblessed on 9/5/24.
//

#ifndef NOOK_RENDERSHAPESYSTEM_H
#define NOOK_RENDERSHAPESYSTEM_H

#include "../../core/System.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../components/Shape.h"

namespace NOOK {

    class RenderShapeSystem : public System {
    public:
        void init();
        void update(sf::RenderWindow* window);
    private:
        void drawShape(sf::RenderWindow& window, const NOOK::Entity& entity);
        void drawCircleShape(sf::RenderWindow& window, const NOOK::Entity& entity, NOOK::Shape& shape);
        void drawRectangleShape(sf::RenderWindow& window, const NOOK::Entity& entity, NOOK::Shape& shape);
    };

} // NAMESPACE NOOK


#endif //NOOK_RENDERSHAPESYSTEM_H
