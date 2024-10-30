//
// Created by stormblessed on 10/27/24.
//

#ifndef NOOK_DEBUGSYSTEM_H
#define NOOK_DEBUGSYSTEM_H

#include "NOOK/core/System.h"
#include "SFML/Window/Event.hpp"

namespace NOOK {

    class DebugSystem : public System {
    public:
        void init();
        void update(const sf::Event* event);
    };

} // NAMESPACE NOOK

#endif //NOOK_DEBUGSYSTEM_H
