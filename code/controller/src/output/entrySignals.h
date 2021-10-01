#ifndef OUTPUT_ENTRY_SIGNALS_H
#define OUTPUT_ENTRY_SIGNALS_H

#include <Arduino.h>
#include "signalLevel.h"

namespace EntrySignals {

    void setSignal(byte address, SignalLevel primary, SignalLevel secondary);

    void getNextCommand(char* buffer);
    void getRepetitionCommand(char* buffer);

    void reset();

}

#endif
