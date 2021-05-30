#ifndef NETWORK_H
#define NETWORK_H

#include "settings.h"
#include "logic.h"
#include "config.h"

typedef void (*CallbackFunction)(char*,char);

namespace Network {
    void init(CallbackFunction callback);
    void tick();
}

#endif