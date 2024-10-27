//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_SPRITE_H
#define NOOK_SPRITE_H

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

namespace NOOK {

    // TODO: check the smooth, repeated, etc variables of the texture
    struct Sprite {
        sf::Sprite sprite;
        std::string spriteName;
        float width{};
        float height{};
        bool loaded{};
    };

} // NAMESPACE NOOK

#endif //NOOK_SPRITE_H
