#ifndef OUTPUT_LIGHTS_H
#define OUTPUT_LIGHTS_H

#include <Arduino.h>

namespace Lights {

    void setPin(uint8_t address, boolean state);

    void getNextCommand(char* buffer);
    void getRepetitionCommand(char* buffer);

}

#endif