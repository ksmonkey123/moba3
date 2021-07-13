#include "statusLed.h"
#include "settings.h"
#include "timer.h"

static void disable(Timer*) {
    digitalWrite(LED_PIN, false);
}

static Timer* timer;

static void _init() {
    timer = Timer::create(50000L, disable);
    pinMode(LED_PIN, OUTPUT);
}

void StatusLED::blink() {
    if (timer == nullptr) {
        _init();
    }
    digitalWrite(LED_PIN, true);
    timer->start();
}
