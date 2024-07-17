//
// Created by stormblessed on 7/17/24.
//

#pragma once

#ifndef NOOK_ENTITY_H
#define NOOK_ENTITY_H

#include <cstdint>

struct Entity {
    uint32_t id;
    friend bool operator<(const Entity &l, const Entity &r){ return l.id < r.id; };
};

#endif //NOOK_ENTITY_H
