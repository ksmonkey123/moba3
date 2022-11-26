#include "directProxy.h"
#include <Arduino.h>

#ifdef PROXY_AVAIL

static void tick() {
    if (Serial.available() > 0) {
        String incoming = Serial.readStringUntil('\n');
        // prepare for sending
        #ifdef RS485_ENABLE
        digitalWrite(RS485_ENABLE, HIGH);
        #endif
        Serial.println(incoming);
        Serial.flush();
        // finish sending
        #ifdef RS485_ENABLE
        digitalWrite(RS485_ENABLE, LOW);
        #endif
    }
}

void execProxy() {
    while(true) {
        tick();
    }
}

#endif