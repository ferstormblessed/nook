//
// Created by stormblessed on 7/13/24.
//

#ifndef NOOK_NOOKMANAGER_H
#define NOOK_NOOKMANAGER_H

class NookManager {
public:
    static NookManager& getInstance();
    void startUp();
    void shutDown();
private:
    static NookManager* s_instance;
    NookManager();
    ~NookManager();
};

#endif //NOOK_NOOKMANAGER_H
