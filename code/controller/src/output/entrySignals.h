#ifndef OUTPUT_ENTRY_SIGNALS_H
#define OUTPUT_ENTRY_SIGNALS_H

#include <Arduino.h>

namespace EntrySignals {

    enum STATUS {
        HALT = 0,
        FREE = 1,
        SLOW_40 = 2,
        SLOW_60 = 3
    };

    void setSignal(byte address, STATUS primary, STATUS secondary);

    void getNextCommand(char* buffer);

    void reset();

}

#endif