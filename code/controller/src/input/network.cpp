#include <Arduino.h>
#include "network.h"
#include "buttons.h"

static char buffer[3];
static byte buffer_length;

void Network::init() {
    Serial.begin(NETWORK_BAUDRATE);
    Serial.print(F("\n----------------------\n"));
    Serial.print(F("starting controller...\n"));
    Serial.print(F("build date:\n"));
    Serial.print  (F(__DATE__));
    Serial.print  (F(" - "));
    Serial.print(F(__TIME__));
    Serial.print(F("\n----------------------\n"));
    delay(1000);
}

void processCharacter(char c) {
    if (c == '\n') {
        if (buffer_length == 3) {
             Buttons::processInput(buffer);
        }
        buffer_length = 0;
    } else {
        if (buffer_length >= 3) {
            buffer_length = 0;
        } else {
            buffer[buffer_length++] = c;
        }
    }
}

void Network::tick() {
    for (byte i = 0; i < NETWORK_MAX_ITERATIONS && (Serial.available() > 0); i++) {
        char c = Serial.read();
        if (c != 0) {
            processCharacter(c);
        }
    }
}
