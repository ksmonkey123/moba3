#ifndef OUTPUT_EXIT_SIGNALS_H
#define OUTPUT_EXIT_SIGNALS_H

#include <Arduino.h>

namespace ExitSignals {

    void setSignal(byte address, byte data, byte mask);

    void getNextCommand(char* buffer);
    void getRepetitionCommand(char* buffer);

    void reset();

}

#endif
