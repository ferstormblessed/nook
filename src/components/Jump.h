//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_JUMP_H
#define NOOK_JUMP_H

#include "SFML/Window/Keyboard.hpp"

namespace NOOK {

    struct Jump {
        float* force{};
        sf::Keyboard::Key jumpKey = sf::Keyboard::Unknown;;
    };

} // NAMESPACE NOOK

#endif //NOOK_JUMP_H
