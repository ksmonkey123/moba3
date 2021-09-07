#include "display.h"
#include "../utils.h"

// for balanced I/O we need a "virtual" 4th channel
static uint16_t state[4];

void Display::processCommand(char* string) {
    for (byte i = 0; i < 3; i++) {
        byte offset = i * 4;

        char buffer[4] = { string[offset + 2], string[offset + 3], string[offset + 0], string[offset + 1] };

        state[i] = Util::decodeHexString(buffer, 4);
    }
}

uint16_t* Display::getBuffer() {
    return state;
}