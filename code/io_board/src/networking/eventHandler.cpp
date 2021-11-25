#include "eventHandler.h"
#include "../utils.h"

void EventHandler::handle(byte channel, uint16_t state, uint16_t mask) {
    static char buffer[5];
    buffer[3] = '\n';
    buffer[4] = '\0';
    for (byte bit = 0; bit < 16; bit++) {
        // scan mask for a set bit
        uint16_t scanmask = 1 << bit;
        if ((mask & scanmask) != 0) {
            // found a set mask bit
            bool set = (state & scanmask) > 0;

            Util::byteToHex(channel << 4 | bit, buffer);
            buffer[2] = set ? '+' : '-';

            Serial.print(buffer);
        }
    }

}