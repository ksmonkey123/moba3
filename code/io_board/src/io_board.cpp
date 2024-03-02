#include <Arduino.h>

#include "networking/network.h"
#include "model/display.h"
#include "model/buttons.h"
#include "io/transfer.h"
#include "statusLed.h"

void setup() {
    Network::init();
    Transfer::init();
    StatusLED::init();
}

boolean verifyButtons(uint16_t* buffer) {
    for (byte block = 1; block < DEBOUNCE_STEPS; block++) {
        for (byte i = 0; i < 4; i++) {
            if (buffer[0] != buffer[(4 * block) + i]) {
                return false;
            }
        }
    }
    return true;
}

void loop() {
    static uint16_t* displayBuffer = Display::getBuffer();
    static uint16_t buttonBuffer[4 * DEBOUNCE_STEPS];

    for(byte i = 0; i < DEBOUNCE_STEPS; i++) {
        Network::tick();
        Transfer::transfer(displayBuffer, buttonBuffer + (4 * i));
        StatusLED::tick();
        Display::tick();
    }

    if (verifyButtons(buttonBuffer)) {
        Buttons::update(buttonBuffer);
    } else {
        Serial.println("disagree");
    }
}
