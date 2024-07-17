//
// Created by stormblessed on 7/14/24.
//

#ifndef NOOK_GAMELOOPMANAGER_H
#define NOOK_GAMELOOPMANAGER_H

#include "SFML/Graphics.hpp"
#include "Data.h"

class GameLoopManager {
public:
    GameLoopManager();
    ~GameLoopManager();
    void startUp();
    void shutDown();
    void run();
private:
    Data* m_data;
    void update();
    void draw();
    void handleEvents();
};


#endif //NOOK_GAMELOOPMANAGER_H
