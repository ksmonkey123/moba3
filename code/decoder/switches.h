#ifndef SWITCHES_H
#define SWITCHES_H

#include "output.h"
#include "config.h"

namespace Switches {

    struct ChannelState {
        uint32_t startMillis;
        uint8_t state;
        uint8_t pendingState;
    };

    struct Data {
        uint16_t driveTime;
        ChannelState channel[6];
    };

    void init();
    void process(char* buffer, char length);
    void tick();
}

#endif