#include <Arduino.h>

#include "network.h"
#include "buttons.h"

static char buffer[3];
static char buffer_length;

void Network::init() {
    Serial.begin(NETWORK_BAUDRATE);
}

void Network::tick() {
    if (Serial.available()) {
        char c = Serial.read();
        if (c != 0) {
            if (c == '\n') {
                if (buffer_length == 3) {
                    Buttons::processInput(buffer);
                }
                buffer_length = 0;
            } else {
                buffer[buffer_length++] = c;
            }
        }
    }
}
