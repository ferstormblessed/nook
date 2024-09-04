//
// Created by stormblessed on 7/28/24.
//

#pragma once

#ifndef NOOK_RENDERSYSTEM_H
#define NOOK_RENDERSYSTEM_H

#include <memory>
#include "../../core/System.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "../../components/Render.h"
#include "../../core/Coordinator.h"

namespace NOOK {

    class RenderSystem : public System {
    public:
        void init();
        void update();
    private:
        void initObject(NOOK::Render& object);
    };

} // NAMESPACE NOOK


#endif //NOOK_RENDERSYSTEM_H
