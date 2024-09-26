//
// Created by stormblessed on 9/25/24.
//

#pragma once

#ifndef NOOK_B2POLYGONCOMPONENT_H
#define NOOK_B2POLYGONCOMPONENT_H

#include "box2d/collision.h"

namespace NOOK {

    struct b2PolygonComponent {
        struct b2Polygon shape{};
        float width{};
        float height{};
    };

} // NAMESPACE NOOK

#endif //NOOK_B2POLYGONCOMPONENT_H
