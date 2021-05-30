#ifndef SIGNAL_H
#define SIGNAL_H

#include "output.h"
#include "config.h"

namespace Signal {

    struct Data {
        struct SignalState {
            uint8_t state;
            uint8_t pendingState;
            uint32_t shedule;
            void (*step)(SignalState*,boolean);
        } signal[2];
    };

    void init();
    void process(char* buffer, char length);
    void tick();
}

#endif