#include <Arduino.h>
#include "input/network.h"
#include "input/buttons.h"

#include "control/control_modules.h"

#include "output/writer.h"

#include "statusLedFull.h"
#include "timer.h"
#include "async.h"

#ifdef RS485_ENABLE
void setupSerial() {
    digitalWrite(RS485_ENABLE, LOW);
    pinMode(RS485_ENABLE, OUTPUT);
    delay(500);
    digitalWrite(RS485_ENABLE, HIGH);
}
#endif

void setup() {
    #ifdef RS485_ENABLE
    setupSerial();
    #endif
    StatusLED::init();
    StatusLED::blink();
    delay(1000);
    StatusLED::force_on();
    Network::init();
    Buttons::init();
    Display::init();
    initControllers();
    Writer::init();
    StatusLED::force_off();
    StatusLED::blink();
}

void loop() {
    Network::tick();
    Timer::tickTimers();
    async_tick();
}
