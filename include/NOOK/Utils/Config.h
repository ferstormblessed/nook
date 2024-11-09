//
// Created by stormblessed on 9/6/24.
//

#ifndef NOOK_CONFIG_H
#define NOOK_CONFIG_H

#include <string>

namespace NOOK {

    struct Config {
        std::string WINDOW_TITLE{};
        int WIDTH{};
        int HEIGHT{};
        int FRAMES{};
        std::string ASSETS_PATH{};
        std::string AUDIO_DIRECTORY{};
        std::string FONTS_DIRECTORY{};
        std::string SPRITES_DIRECTORY{};
        float GRAVITY{};
        float HIT_THRESHOLD{};
    };

} // NAMESPACE NOOK

#endif //NOOK_CONFIG_H
