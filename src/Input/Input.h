//
// Created by stormblessed on 9/4/24.
//

#pragma once

#ifndef NOOK_INPUT_H
#define NOOK_INPUT_H


#include "../core/System.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace NOOK {

    class Input : public System {
    public:
        void init();
        void update(const sf::Event& event);
        bool isKeyDown(sf::Keyboard::Key key);
        bool isMouseButtonDown(sf::Mouse::Button button);
        sf::Vector2i getMousePosition(sf::RenderWindow& window);
    private:

    };

} // NAMESPACE NOOK

#endif //NOOK_INPUT_H
