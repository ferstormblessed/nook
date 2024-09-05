//
// Created by stormblessed on 9/5/24.
//

#pragma once

#ifndef NOOK_RENDERTEXTSYSTEM_H
#define NOOK_RENDERTEXTSYSTEM_H

#include "../../core/System.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace NOOK {

    class RenderTextSystem : public System {
    public:
        void init();
        void update(sf::RenderWindow& window);
    private:
        void renderText();
    };

} // NAMESPACE NOOK


#endif //NOOK_RENDERTEXTSYSTEM_H
