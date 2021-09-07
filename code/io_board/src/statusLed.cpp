#include "statusLed.h"
#include "settings.h"

void StatusLED::init() {
    pinMode(LED_PIN, OUTPUT);
    StatusLED::blink();
}

static unsigned long enableTime = 0;

void StatusLED::tick() {
    if (enableTime + 20 < millis()) {
        digitalWrite(LED_PIN, LOW);
    }
}

void StatusLED::blink() {
    enableTime = millis();
    digitalWrite(LED_PIN, HIGH);
}
