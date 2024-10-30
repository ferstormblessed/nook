//
// Created by stormblessed on 9/5/24.
//

#pragma once

#ifndef NOOK_RECTANGLESHAPE_H
#define NOOK_RECTANGLESHAPE_H

#include "memory"
#include "SFML/Graphics/RectangleShape.hpp"

namespace NOOK {

    struct RectangleShape {
        std::shared_ptr<sf::RectangleShape> shape{};
        float* height{};
        float* width{};
    };

} // NAMESPACE NOOK

#endif //NOOK_RECTANGLESHAPE_H
