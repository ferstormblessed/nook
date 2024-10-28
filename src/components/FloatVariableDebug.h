//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_FLOATVARIABLEDEBUG_H
#define NOOK_FLOATVARIABLEDEBUG_H

#include <string>

namespace NOOK {

    struct FloatVariableDebug {
        std::string name{};
        float* value{};
    };

} // NAMESPACE NOOK

#endif //NOOK_FLOATVARIABLEDEBUG_H
