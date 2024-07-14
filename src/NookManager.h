//
// Created by stormblessed on 7/13/24.
//

#ifndef NOOK_NOOKMANAGER_H
#define NOOK_NOOKMANAGER_H

#include "GameLoopManager.h"

class NookManager {
public:
    static NookManager& getInstance();
    void startUp();
    void shutDown();
private:
    static NookManager* m_instance;
    GameLoopManager* m_gameLoopManager{};
    NookManager();
    ~NookManager();
};

#endif //NOOK_NOOKMANAGER_H
