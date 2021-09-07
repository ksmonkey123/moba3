#include "buttons.h"
#include "../networking/eventHandler.h"
#include "../statusLed.h"

static uint16_t state[4];

void Buttons::update(uint16_t* buffer) {
    for (byte i = 0; i < 4; i++) {
        uint16_t mask = state[i] ^ buffer[i];
        state[i] = buffer[i];

        if (mask != 0) {
            StatusLED::blink();
            EventHandler::handle(i, state[i], mask);
        }
    }

}