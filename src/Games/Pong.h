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

    void Pong(const NOOK::Config& config) {
        // Paddles
        NOOK::Entity l_paddle = gCoordinator.createEntity();
        NOOK::Entity r_paddle = gCoordinator.createEntity();

        gCoordinator.addComponent(l_paddle, NOOK::Shape{ .isRectangle = true, .color = sf::Color::White });
        gCoordinator.addComponent(l_paddle, NOOK::RectangleShape{ .height = 200.f, .width = 20.f });
        gCoordinator.addComponent(l_paddle, NOOK::Transform{ .position = b2Vec2(30.f, config.HEIGHT/2 - 100)});
        gCoordinator.addComponent(l_paddle,
                                  NOOK::PlayerMove{
                                          .speed = 10.f,
                                          .up = sf::Keyboard::Key::W,
                                          .down = sf::Keyboard::Key::S,
                                          .right = sf::Keyboard::Key::Unknown,
                                          .left = sf::Keyboard::Key::Unknown
                                  });

        gCoordinator.addComponent(r_paddle, NOOK::Shape{ .isRectangle = true, .color = sf::Color::White });
        gCoordinator.addComponent(r_paddle, NOOK::RectangleShape{ .height = 200.f, .width = 20.f });
        gCoordinator.addComponent(r_paddle, NOOK::Transform{ .position = b2Vec2(config.WIDTH - 50.f, config.HEIGHT/2 - 100)});
        gCoordinator.addComponent(r_paddle,
                                  NOOK::PlayerMove{
                                          .speed = 10.f,
                                          .up = sf::Keyboard::Key::Up,
                                          .down = sf::Keyboard::Key::Down,
                                          .right = sf::Keyboard::Key::Unknown,
                                          .left = sf::Keyboard::Key::Unknown
                                  });
    }

} // NAMESPACE NOOK

#endif //NOOK_PONG_H
