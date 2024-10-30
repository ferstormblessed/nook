//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_PAUSE_H
#define NOOK_PAUSE_H

#include "SFML/Window/Keyboard.hpp"

namespace NOOK {

    struct Pause {
        bool isPaused{};
        sf::Keyboard::Key pauseKey = sf::Keyboard::Key::Unknown;
        void (*onPauseFunction)(const Entity entity){};
    };

} // NAMESPACE NOOK

#endif //NOOK_PAUSE_H
