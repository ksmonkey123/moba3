#include <Arduino.h>
#include "network.h"
#include "buttons.h"

void setup() {
    Buttons::init();
    Network::init();
}

void loop() {
    Network::tick();
}
