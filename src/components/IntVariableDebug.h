//
// Created by stormblessed on 10/27/24.
//

#pragma once

#ifndef NOOK_INTVARIABLEDEBUG_H
#define NOOK_INTVARIABLEDEBUG_H

#include <string>

namespace NOOK {

    struct IntVariableDebug {
        std::string name{};
        int* value{};
    };

} // NAMESPACE NOOK

#endif //NOOK_INTVARIABLEDEBUG_H
