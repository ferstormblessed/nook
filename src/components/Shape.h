//
// Created by stormblessed on 9/4/24.
//

#pragma once

#ifndef NOOK_SHAPE_H
#define NOOK_SHAPE_H

#include "SFML/Graphics/Color.hpp"
#include "../../cmake-build-release/_deps/sfml-src/include/SFML/Graphics/Texture.hpp"

namespace NOOK {

    struct Shape {
        bool isCircle;
        bool isRectangle;
        bool isLine;
        sf::Texture texture{};
        sf::Color color;
        sf::Color outlineColor;
        float outlineThickness;
    };

} // NAMESPACE NOOK

#endif //NOOK_SHAPE_H
