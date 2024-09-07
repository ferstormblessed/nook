//
// Created by stormblessed on 9/4/24.
//

#pragma once

#ifndef NOOK_CIRCLESHAPE_H
#define NOOK_CIRCLESHAPE_H

#include "SFML/Graphics/CircleShape.hpp"
#include "memory"

namespace NOOK {

    struct CircleShape {
        std::shared_ptr<sf::CircleShape> shape{};
        float radius{};
        int numSides{};
    };

} // NAMESPACE NOOK

#endif //NOOK_CIRCLESHAPE_H
