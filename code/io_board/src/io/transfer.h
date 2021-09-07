#ifndef OUTPUT_H
#define OUTPUT_H

#include <Arduino.h>

namespace Transfer {

    void init();
    bool transfer(uint16_t* display, uint16_t* buttons);

};

#endif