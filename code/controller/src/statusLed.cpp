#include "statusLed.h"
#include "statusLedFull.h"
#include "settings.h"
#include "timer.h"

static void disable(Timer*) {
    digitalWrite(LED_PIN, false);
}

static Timer* timer;

static void _init() {
    timer = Timer::create(LED_PULSE_DURATION, disable);
    pinMode(LED_PIN, OUTPUT);
}

void StatusLED::force_on() {
    digitalWrite(LED_PIN, true);
}

void StatusLED::force_off() {
    digitalWrite(LED_PIN, false);
}

void StatusLED::blink() {
    if (timer == nullptr) {
        _init();
    }
    digitalWrite(LED_PIN, true);
    timer->start();
}
