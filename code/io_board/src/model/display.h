#ifndef MODEL_DISPLAY_H
#define MODEL_DISPLAY_H

#include <Arduino.h>

namespace Display {
    void processCommand(char* buffer);
    uint16_t* getBuffer();
}

#endif
