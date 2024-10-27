//
// Created by stormblessed on 10/6/24.
//

#pragma once

#ifndef NOOK_LOGIC_H
#define NOOK_LOGIC_H

#include "../core/Types.h"

namespace NOOK {

    struct Logic {
        std::string name{};
        void (*gameLogicFunction)(const NOOK::Entity entity){};
    };

} // NAMESPACE NOOK

#endif //NOOK_LOGIC_H
