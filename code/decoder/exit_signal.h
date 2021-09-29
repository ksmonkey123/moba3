#ifndef EXIT_SIGNAL_H
#define EXIT_SIGNAL_H

#include "output.h"
#include "config.h"

namespace ExitSignal {

    struct Data {
        struct SignalState {
            uint8_t state;
            uint8_t pendingState;
            uint32_t schedule;
            void (*step)(SignalState*,byte);
        } signal[4];
    };

    void init();
    void process(char* buffer, char length);
    void tick();
}

#endif