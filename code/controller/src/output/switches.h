#ifndef OUTPUT_SWITCHES_H
#define OUTPUT_SWITCHES_H

#include <Arduino.h>

namespace Switches {

    enum ForcedUpdateState { IDLE, ARMED, RUNNING };

    enum STATUS {
        UNKNOWN = 0,
        STRAIGHT = 'a',
        DIVERGING = 'b'
    };

    void setSwitch(byte address, STATUS state);

    void sendForcedUpdates();

    void getNextCommand(char* buffer);

    void reset();

}

#endif
