#ifndef OUTPUT_H
#define OUTPUT_H

#include <Arduino.h>

namespace Output {
    struct Config {
        uint16_t mask;
        boolean inverted;
    };
    
    void init(uint16_t state, Output::Config* config);
    void clear();
    void fill();
    void setMask(uint16_t mask);
    void clearMask(uint16_t mask);
    void setState(uint16_t state);
};

#endif