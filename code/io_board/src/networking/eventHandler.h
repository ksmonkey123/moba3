#ifndef NETWORKING_EVENTHANDLER_H
#define NETWORKING_EVENTHANDLER_H

#include <Arduino.h>

namespace EventHandler {
    void handle(byte channel, uint16_t state, uint16_t mask);
}

#endif