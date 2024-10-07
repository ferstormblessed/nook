//
// Created by stormblessed on 10/6/24.
//

#pragma once

#ifndef NOOK_GAMELOGICSYSTEM_H
#define NOOK_GAMELOGICSYSTEM_H

#include "../../core/System.h"

namespace NOOK {

    class GameLogicSystem : public NOOK::System {
    public:
        void init();
        void update();
    private:
    };

} // NAMESPACE NOOK


#endif //NOOK_GAMELOGICSYSTEM_H
