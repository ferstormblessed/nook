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
        float speed{};

        sf::Keyboard::Key up{};
        sf::Keyboard::Key down{};
        sf::Keyboard::Key right{};
        sf::Keyboard::Key left{};
    };

} // NAMESPACE NOOK

#endif //NOOK_PLAYERMOVE_H
