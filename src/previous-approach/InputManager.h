//
// Created by stormblessed on 7/15/24.
//

#ifndef NOOK_INPUTMANAGER_H
#define NOOK_INPUTMANAGER_H


#include "SFML/Graphics.hpp"
#include "Data.h"

class InputManager {
public:
    InputManager();
    ~InputManager();
    void startUp();
    void shutDown();
    void processInput();
    static bool isKeyPressed(sf::Keyboard::Key key);
private:
    Data* m_data;
};


#endif //NOOK_INPUTMANAGER_H
