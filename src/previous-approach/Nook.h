//
// Created by stormblessed on 7/13/24.
//

#ifndef NOOK_NOOK_H
#define NOOK_NOOK_H

#include "Data.h"

class Nook {
public:
    Nook();
    ~Nook();
    void startUp();
    void shutDown();
private:
    Data* m_data;
};

#endif //NOOK_NOOK_H
