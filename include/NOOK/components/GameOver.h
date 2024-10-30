//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_GAMEOVER_H
#define NOOK_GAMEOVER_H

#include "NOOK/core/Types.h"

namespace NOOK {

    struct GameOver {
        bool isOver{};
        bool playAgain{};
        void (*gameOverFunction)(const Entity entity){};
        void (*playAgainFunction)(const Entity entity){};
    };

} // NAMESPACE NOOK

#endif //NOOK_GAMEOVERSCREEN_H
