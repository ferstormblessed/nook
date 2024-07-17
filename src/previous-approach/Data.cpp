//
// Created by stormblessed on 7/16/24.
//

#include "Data.h"
#include "spdlog/spdlog.h"

Data* Data::s_instance = nullptr;

Data::Data() {
    spdlog::warn("DATA CREATED");
}

Data::~Data() {
    spdlog::warn("DATA DESTROYED");
}

Data* Data::getInstance() {
    spdlog::info("Getting instance of Data");
    if (s_instance == nullptr) {
        s_instance = new Data{};
        return s_instance;
    }
    return s_instance;
}

void Data::starUp(sf::RenderWindow *window) {
    spdlog::info("Starting up Data");
    m_window = window;
    m_runnig = true;
}
void Data::shutDown() {
    spdlog::info("Shutting down Data");
}

sf::RenderWindow *Data::getWindow() {
    return m_window;
}

sf::Clock *Data::getClock() {
    return &m_deltaClock;
}

bool Data::getRunning() {
    return m_runnig;
}

