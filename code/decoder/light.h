#ifndef LIGHT_H
#define LIGHT_H

#include "output.h"
#include "config.h"

namespace Light {
    void init();
    void process(char* buffer, char length);
}

#endif