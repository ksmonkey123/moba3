#include <Arduino.h>

#include "networking/network.h"
#include "model/display.h"
#include "model/buttons.h"
#include "io/transfer.h"
#include "statusLed.h"

void setup() {
    Network::init();
    Transfer::init();
    StatusLED::init();
}

void loop() {
    static uint16_t* displayBuffer = Display::getBuffer();
    static uint16_t buttonBuffer[4];

    Network::tick();
    Transfer::transfer(displayBuffer, buttonBuffer);
    Buttons::update(buttonBuffer);
    StatusLED::tick();
    Display::tick();
}
