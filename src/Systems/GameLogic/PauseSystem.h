//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_PAUSESYSTEM_H
#define NOOK_PAUSESYSTEM_H

#include "../../core/System.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Event.hpp"

namespace NOOK {

    class PauseSystem : public System {
    public:
        void init();
        void update(sf::Event* event, GAME_STATE& gameState);
    };

} // NAMESPACE NOOK


#endif //NOOK_PAUSESYSTEM_H
