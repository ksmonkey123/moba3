#include "display.h"
#include "../utils.h"
#include "../settings.h"

// for balanced I/O we need a "virtual" 4th channel
static uint16_t state[4] = {0x2000, 0, 0, 0};
static uint32_t lastUpdate;
static uint32_t lastChange;

void Display::tick() {
    auto current = millis();

    bool red_led = (lastUpdate + NO_UPDATE_TIMEOUT < current)  // no long since last update
                 | (lastChange + UPDATE_TICK_PULSE > current); // tick because of change
    
    state[0] &= 0xdfff;
    if (!red_led) {
        state[0] |= 0x2000;
    }
}

void Display::processCommand(char* string) {
    lastUpdate = millis();
    for (byte i = 0; i < 3; i++) {
        byte offset = i * 4;

        char buffer[4] = { string[offset + 2], string[offset + 3], string[offset + 0], string[offset + 1] };

        uint16_t old = state[i];
        auto next_state = Util::decodeHexString(buffer, 4);
        if (next_state != -1) {
            state[i] = next_state & 0xffff;
            if (old != state[i]) {
                lastChange = millis();
            }
        }
    }
}

uint16_t* Display::getBuffer() {
    return state;
}