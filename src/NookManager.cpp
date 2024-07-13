//
// Created by stormblessed on 7/13/24.
//

#include "NookManager.h"
#include <iostream>

NookManager* NookManager::s_instance = nullptr;

NookManager& NookManager::getInstance() {
    if (s_instance == nullptr) {
        std::cout << "s_instance was a nullptr" << std::endl;
        s_instance = new NookManager{};
        std::cout << "memory address is = " << &s_instance << std::endl;
        return *s_instance;
    }
    std::cout << "memory address is = " << &s_instance << std::endl;
    std::cout << "returning previously existing instance" << std::endl;
    return *s_instance;
}

void NookManager::startUp() {
    std::cout << "starting up NookManager" << std::endl;
}

void NookManager::shutDown() {
    std::cout << "shutting down NookManager" << std::endl;
}

NookManager::NookManager() = default;
NookManager::~NookManager() = default;



