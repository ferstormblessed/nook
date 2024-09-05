//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_SPRITE_H
#define NOOK_SPRITE_H

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

namespace NOOK {

    struct Sprite {
        sf::Texture texture;
        sf::Sprite sprite;
        std::string image;
        bool loaded{};
    };

} // NAMESPACE NOOK

#endif //NOOK_SPRITE_H
