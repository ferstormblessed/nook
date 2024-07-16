//
// Created by stormblessed on 7/14/24.
//

#include "GameLoopManager.h"
#include "imgui-SFML.h"
#include "spdlog/spdlog.h"
#include "gui.h"

GameLoopManager* GameLoopManager::s_instance = nullptr;

GameLoopManager& GameLoopManager::getInstance() {
    spdlog::info("Getting instance of GameLoopManager");
    if (s_instance == nullptr) {
        spdlog::info("s_instance is nullptr");
        s_instance = new GameLoopManager{};
        return *s_instance;
    }
    spdlog::info("Returning previously existing instance");
    return *s_instance;
}

void GameLoopManager::startUp(sf::RenderWindow* window, InputManager* inputManager) {
    spdlog::info("Starting up GameLoopManager");
    m_window = window;
    m_running = true;
    m_inputManager = inputManager;

    // initialize ImGui::SFML
    if (!ImGui::SFML::Init(*m_window)) {
        spdlog::error("Failed to load window through ImGui::SFML");
        return;
    }
}

void GameLoopManager::update() {
    spdlog::info("Update method from GameLoopManager");
}

void GameLoopManager::draw() {
    spdlog::info("Draw method from GameLoopManager");
}

void GameLoopManager::run() {
    spdlog::info("Starting Game Loop");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (m_running) {

        m_inputManager->processInput();
        update();
        draw();

        handleEvents();
        ImGui::SFML::Update(*m_window, m_deltaClock.restart());
        m_window->clear();
        update();
        draw();
        gui();
        m_window->draw(shape);
        ImGui::SFML::Render(*m_window);
        m_window->display();
    }
    ImGui::SFML::Shutdown();
    spdlog::info("Exiting game loop");
}

void GameLoopManager::handleEvents() {
    sf::Event event{};
    while (m_window->pollEvent(event)) {
        ImGui::SFML::ProcessEvent(*m_window, event);

        if (event.type == sf::Event::Closed) {
            m_running = false;
            m_window->close();
        }
    }

}

void GameLoopManager::shutDown() {
    spdlog::info("Shutting down GameLoopManager");
    m_window = nullptr;
    m_running = false;
    m_deltaClock = {};
}

GameLoopManager::GameLoopManager() = default;
GameLoopManager::~GameLoopManager() = default;
