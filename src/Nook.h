//
// Created by stormblessed on 7/13/24.
//

#ifndef NOOK_NOOK_H
#define NOOK_NOOK_H

#include "GameLoopManager.h"
#include "InputManager.h"

class Nook {
public:
    static Nook& getInstance();
    void startUp();
    void shutDown();
private:
    static Nook* s_instance;
    GameLoopManager* m_gameLoopManager;
    InputManager* m_inputManager;
    Nook();
    ~Nook();
};

#endif //NOOK_NOOK_H
