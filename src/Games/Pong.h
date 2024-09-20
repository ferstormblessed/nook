//
// Created by stormblessed on 9/19/24.
//

#pragma once

#ifndef NOOK_PONG_H
#define NOOK_PONG_H

#include "../core/Types.h"
#include "../core/Coordinator.h"
#include "../components/Shape.h"
#include "../components/RectangleShape.h"
#include "../components/Transform.h"
#include "../components/PlayerMove.h"
#include "../Config.h"
#include "../Register.h"

namespace NOOK {

    void paddles(const NOOK::Config& config) {
        // Paddles
        NOOK::Entity l_paddle = gCoordinator.createEntity();
        NOOK::Entity r_paddle = gCoordinator.createEntity();

        // Left paddle components
        // Shape component
        NOOK::Shape l_shape;
        l_shape.isRectangle = true;
        l_shape.color = sf::Color::White;
        // RectangleShape component
        NOOK::RectangleShape l_rectangleShape;
        l_rectangleShape.height = 200.f;
        l_rectangleShape.width = 20.f;
        // Transform component
        NOOK::Transform l_transform;
        l_transform.position = b2Vec2(30.f, config.HEIGHT/2 - 100);
        // PlayerMove component
        NOOK::PlayerMove l_playerMove;
        l_playerMove.speed = 10.f;
        l_playerMove.up = sf::Keyboard::Key::W;
        l_playerMove.down = sf::Keyboard::Key::S;

        // Right paddle components
        // Shape component
        NOOK::Shape r_shape;
        r_shape.isRectangle = true;
        r_shape.color = sf::Color::White;
        // RectangleShape component
        NOOK::RectangleShape r_rectangleShape;
        r_rectangleShape.height = 200.f;
        r_rectangleShape.width = 20.f;
        // Transform component
        NOOK::Transform r_transform;
        r_transform.position = b2Vec2(config.WIDTH - 50.f, config.HEIGHT/2 - 100);
        // PlayerMove component
        NOOK::PlayerMove r_playerMove;
        r_playerMove.speed = 10.f;
        r_playerMove.up = sf::Keyboard::Key::Up;
        r_playerMove.down = sf::Keyboard::Key::Down;

        // Add components to Left paddle
        gCoordinator.addComponent(l_paddle, l_shape);
        gCoordinator.addComponent(l_paddle, l_rectangleShape);
        gCoordinator.addComponent(l_paddle, l_transform);
        gCoordinator.addComponent(l_paddle, l_playerMove);
        // Add components to Right paddle
        gCoordinator.addComponent(r_paddle, r_shape);
        gCoordinator.addComponent(r_paddle, r_rectangleShape);
        gCoordinator.addComponent(r_paddle, r_transform);
        gCoordinator.addComponent(r_paddle, r_playerMove);
    }

    void Pong(const NOOK::Config& config) {
        paddles(config);
    }

} // NAMESPACE NOOK

#endif //NOOK_PONG_H
