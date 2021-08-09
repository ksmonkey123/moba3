#include <Arduino.h>
#include "input/network.h"
#include "input/buttons.h"
#include "control/control_modules.h"
#include "timer.h"
#include "output/writer.h"
#include "statusLed.h"

void setup() {
    delay(500);
    Network::init();
    Buttons::init();
    initControllers();
    Writer::init();
    StatusLED::blink();
}

void loop() {
    Network::tick();
    Timer::tickTimers();
}
