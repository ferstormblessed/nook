//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_JUMPSYSTEM_H
#define NOOK_JUMPSYSTEM_H

#include "SFML/Window/Event.hpp"
#include "NOOK/components/RigidBody.h"
#include "NOOK/components/Jump.h"
#include "SFML/Window/Keyboard.hpp"

namespace NOOK {

    class JumpSystem : public System {
    public:
        void init();
        void update(sf::Event* event, const GAME_STATE& gameState);
    private:
        void jump(RigidBody &rb, const Jump &jump, const sf::Keyboard::Key &key);
    };

} // NAMESPACE NOOK

#endif //NOOK_JUMPSYSTEM_H
