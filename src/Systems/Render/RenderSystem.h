//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_RENDERSYSTEM_H
#define NOOK_RENDERSYSTEM_H

#include <memory>
#include "../../core/System.h"
#include "../../components/Render.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../components/Transform.h"

namespace NOOK {

    class RenderSystem : public System {
    public:
        void init();
        void update(sf::RenderWindow* window);
    private:
        void initObject(NOOK::Render& render);
    };

} // NAMESPACE NOOK


#endif //NOOK_RENDERSYSTEM_H
