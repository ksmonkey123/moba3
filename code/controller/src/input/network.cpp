#include <Arduino.h>
#include "network.h"
#include "buttons.h"
#include "../directProxy.h"

static char buffer[3];
static byte buffer_length;

#ifdef PROXY_AVAIL
void setupProxyMode() {
    delay(200);
    #ifdef RS485_ENABLE
    digitalWrite(RS485_ENABLE, LOW);
    #endif
    Serial.print(F("# type '.' for direct proxy mode...\n"));
    delay(2000);
    bool proxy;
    if (Serial.available() > 0 && Serial.read() == '.') {
        Serial.print(F("# entering proxy mode\n"));
        proxy = true;
    } else {
        Serial.print(F("# resuming normal startup\n"));
        proxy = false;
    }
    while(Serial.available() > 0) {
        Serial.read();
    }
    if (proxy) {
        execProxy();
    }
    #ifdef RS485_ENABLE
    digitalWrite(RS485_ENABLE, HIGH);
    #endif
}
#endif

void Network::init() {
    #ifdef RS485_ENABLE
        digitalWrite(RS485_ENABLE, LOW);
        pinMode(RS485_ENABLE, OUTPUT);
        delay(500);
        digitalWrite(RS485_ENABLE, HIGH);
    #endif
    Serial.begin(NETWORK_BAUDRATE);
    Serial.print(F("\n# ----------------------\n"));
    Serial.print(F("# starting controller...\n"));
    Serial.print(F("# build date:\n# "));
    Serial.print(F(__DATE__));
    Serial.print(F(" - "));
    Serial.print(F(__TIME__));
    Serial.print(F("\n# ----------------------\n"));
    #ifdef PROXY_AVAIL
    setupProxyMode();
    #endif
    delay(1000);
}



void processCharacter(char c) {
    if (c == '\r') {
        // ignore CR
    } else if (c == '\n') {
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
