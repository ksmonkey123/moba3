#include <Arduino.h>
#include "input/network.h"
#include "input/buttons.h"
#include "control/control_modules.h"
#include "timer.h"
#include "output/writer.h"

void setup() {
    Buttons::init();
    Network::init();
    initControllers();
    Writer::init();
}

void loop() {
    Network::tick();
    Timer::tickTimers();
}
