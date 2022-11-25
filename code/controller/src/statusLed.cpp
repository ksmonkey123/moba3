#include "statusLed.h"
#include "statusLedFull.h"
#include "settings.h"
#include "timer.h"
#include "async.h"

void StatusLED::init() {
    pinMode(LED_PIN, OUTPUT);
}

void StatusLED::force_on() {
    digitalWrite(LED_PIN, true);
}

void StatusLED::force_off() {
    digitalWrite(LED_PIN, false);
}

void StatusLED::blink() {
    StatusLED::force_on();
    async_unique(StatusLED::force_off, LED_PULSE_DURATION);
}
