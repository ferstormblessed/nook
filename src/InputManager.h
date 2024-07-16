//
// Created by stormblessed on 7/15/24.
//

#ifndef NOOK_INPUTMANAGER_H
#define NOOK_INPUTMANAGER_H


#include <SFML/Graphics.hpp>
#include <string>

class InputManager {
public:
    static InputManager& getInstance();
    void startUp(sf::RenderWindow* window);
    void shutDown();
    void processInput();
    static bool isKeyPressed(sf::Keyboard::Key key);
private:
    static InputManager* s_instance;
    sf::RenderWindow* m_window;
    InputManager();
    ~InputManager();
};


#endif //NOOK_INPUTMANAGER_H
