#include <Arduino.h>
#include "input/network.h"
#include "input/buttons.h"
#include "control/control.h"
#include "output/writer.h"

void setup() {
    Buttons::init();
    Network::init();
    Control::init();
    Writer::init();
}

void loop() {
    Network::tick();
    Control::tick();
    Writer::tick();
}
