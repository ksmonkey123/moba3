#ifndef MACROS_H
#define MACROS_H

#include "settings.h"

#define RETRANSMIT_GUARD() \
    static unsigned long lastCall = 0; \
    if (lastCall + COMMAND_REPETITION_PERIOD > millis()) return; \
    lastCall = millis();

#define ARRAY_LENGTH(array) \
    sizeof(array) / sizeof(*array)

#define NEXTVAL(var, max) \
    if (++var == max) { var = 0; }

#endif
