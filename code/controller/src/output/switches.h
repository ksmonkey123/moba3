#ifndef OUTPUT_SWITCHES_H
#define OUTPUT_SWITCHES_H

#include <Arduino.h>

namespace Switches {

    enum STATUS {
        UNKNOWN = 0,
        STRAIGHT = 'a',
        DIVERGING = 'b'
    };

    void setSwitch(byte address, STATUS state);

    void getNextCommand(char* buffer);

}
 
#endif
