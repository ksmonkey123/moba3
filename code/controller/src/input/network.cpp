#include <Arduino.h>
#include "network.h"
#include "buttons.h"

static char buffer[3];
static char buffer_length;

void Network::init() {
    Serial.begin(NETWORK_BAUDRATE);
    Serial.println();
    Serial.println("----------------------");
    Serial.println("starting controller...");
    Serial.println("build date:");
    Serial.print  (__DATE__);
    Serial.print  (" - ");
    Serial.println(__TIME__);
    Serial.println("----------------------");
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
