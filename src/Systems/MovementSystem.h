//
// Created by stormblessed on 9/8/24.
//

#pragma once

#ifndef NOOK_MOVEMENTSYSTEM_H
#define NOOK_MOVEMENTSYSTEM_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Event.hpp"
#include "../core/System.h"
#include "../components/PlayerMove.h"
#include "../components/Transform.h"

namespace NOOK {

    class MovementSystem : public System {
    public:
        void init();
        void update(sf::Event* event);
    private:
        void moveWithKeyboard(NOOK::Transform& transform, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key);
    };

} // NAMESPACE NOOK


#endif //NOOK_MOVEMENTSYSTEM_H
