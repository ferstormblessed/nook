//
// Created by stormblessed on 7/14/24.
//

#ifndef NOOK_GAMELOOPMANAGER_H
#define NOOK_GAMELOOPMANAGER_H

#include <SFML/Graphics.hpp>
#include <functional>
#include "InputManager.h"

class GameLoopManager {
public:
    static GameLoopManager& getInstance();
    void startUp(sf::RenderWindow* window, InputManager* inputManager);
    void shutDown();
    void run();
private:
    static GameLoopManager* s_instance;
    InputManager* m_inputManager;
    sf::RenderWindow* m_window;
    sf::Clock m_deltaClock;
    bool m_running;
    void update();
    void draw();
    void handleEvents();
    GameLoopManager();
    ~GameLoopManager();
};


#endif //NOOK_GAMELOOPMANAGER_H
