#include <Arduino.h>
#include "network.h"
#include "buttons.h"

static char buffer[3];
static byte buffer_length;

void Network::init() {
    Serial.begin(NETWORK_BAUDRATE);
    Serial.println();
    Serial.println(F("----------------------"));
    Serial.println(F("starting controller..."));
    Serial.println(F("build date:"));
    Serial.print  (F(__DATE__));
    Serial.print  (F(" - "));
    Serial.println(F(__TIME__));
    Serial.println(F("----------------------"));
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
