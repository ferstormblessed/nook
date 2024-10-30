//
// Created by stormblessed on 9/8/24.
//

#pragma once

#ifndef NOOK_MOVEMENTSYSTEM_H
#define NOOK_MOVEMENTSYSTEM_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Event.hpp"
#include "../../core/System.h"
#include "../../components/PlayerMove.h"
#include "../../components/Transform.h"
#include "../../components/RigidBody.h"

namespace NOOK {

    class MovementSystem : public System {
    public:
        void init();
        void update(sf::Event* event, const GAME_STATE& gameState);
    private:
        void moveWithKeyboard(NOOK::RigidBody& rb, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key);
        void moveUp(NOOK::RigidBody& rb, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key, b2Vec2& velocity);
        void moveDown(NOOK::RigidBody& rb, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key, b2Vec2& velocity);
        void moveRight(NOOK::RigidBody& rb, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key, b2Vec2& velocity);
        void moveLeft(NOOK::RigidBody& rb, const NOOK::PlayerMove& playerMove, const sf::Keyboard::Key& key, b2Vec2& velocity);
    };

} // NAMESPACE NOOK


#endif //NOOK_MOVEMENTSYSTEM_H
