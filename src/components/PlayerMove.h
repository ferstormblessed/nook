//
// Created by stormblessed on 9/18/24.
//

#pragma once

#ifndef NOOK_PLAYERMOVE_H
#define NOOK_PLAYERMOVE_H

#include <vector>
#include "SFML/Window/Keyboard.hpp"

namespace NOOK {

    struct PlayerMove {
        float* speed{};
        sf::Keyboard::Key up = sf::Keyboard::Unknown;
        sf::Keyboard::Key down = sf::Keyboard::Unknown;
        sf::Keyboard::Key right = sf::Keyboard::Unknown;
        sf::Keyboard::Key left = sf::Keyboard::Unknown;;
    };

} // NAMESPACE NOOK

#endif //NOOK_PLAYERMOVE_H
