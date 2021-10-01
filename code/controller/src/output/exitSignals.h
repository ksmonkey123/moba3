#ifndef OUTPUT_EXIT_SIGNALS_H
#define OUTPUT_EXIT_SIGNALS_H

#include <Arduino.h>
#include "signalLevel.h"

namespace ExitSignals {

    void setSignal(byte chipAddress, byte channel, SignalLevel level);

    void getNextCommand(char* buffer);
    void getRepetitionCommand(char* buffer);

    void reset();

}

#endif
