//
// Created by stormblessed on 7/16/24.
//

#ifndef NOOK_DATA_H
#define NOOK_DATA_H

#include "SFML/Graphics.hpp"

class Data {
public:
    static Data* getInstance();
    void starUp(sf::RenderWindow* window);
    void shutDown();
    sf::RenderWindow* getWindow();
    sf::Clock* getClock();
    bool getRunning();
private:
    static Data* s_instance;
    sf::Clock m_deltaClock;
    bool m_runnig;
    sf::RenderWindow* m_window;
    Data();
    ~Data();
};


#endif //NOOK_DATA_H
