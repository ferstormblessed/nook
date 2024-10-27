//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_DEBUG_H
#define NOOK_DEBUG_H

#include <string>

namespace NOOK {

    enum DEBUG_TYPE {
        INT,
        FLOAT,
        BOOL
    };

    struct Debug {
        DEBUG_TYPE type{};
        bool debugOn{};
        sf::Keyboard::Key toggleDebug = sf::Keyboard::Key::Unknown;
    };

} // NAMESPACE NOOK

#endif //NOOK_DEBUG_H
