//
// Created by stormblessed on 7/14/24.
//

#ifndef NOOK_GAMELOOPMANAGER_H
#define NOOK_GAMELOOPMANAGER_H

#include <SFML/Graphics.hpp>
#include <functional>

class GameLoopManager {
public:
    static GameLoopManager& getInstance();
    void init(sf::RenderWindow& window,
              const std::function<void()>& updateCallback,
              const std::function<void()>& drawCallback);
    void startUp();
    void shutDown();
    void run();
private:
    GameLoopManager();
    ~GameLoopManager();
    static GameLoopManager* m_instance;
    sf::RenderWindow* m_window{};
    sf::Clock m_deltaClock{};
    bool m_running{true};
    std::function<void()> m_updateCallback{nullptr};
    std::function<void()> m_drawCallback{nullptr};
    void handleEvents();
};


#endif //NOOK_GAMELOOPMANAGER_H
