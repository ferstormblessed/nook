//
// Created by stormblessed on 9/5/24.
//

#pragma once

#ifndef NOOK_TEXT_H
#define NOOK_TEXT_H

#include <string>
#include "SFML/Graphics/Color.hpp"

namespace NOOK {

    struct Text {
        std::string* font{};
        std::string* text{};
        int* size{};
        sf::Color color{};
        sf::Color outlineColor{};
        float* outlineThickness{};
        float* lineSpacing{};
        float* letterSpacing{};
        bool* isBold{};
        bool* isItalic{};
        bool* isUnderlined{};
        bool* isStrikeThrough{};
    };

} // NAMESPACE NOOK

#endif //NOOK_TEXT_H
