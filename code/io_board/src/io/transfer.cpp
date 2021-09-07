#include <Arduino.h>
#include <SPI.h>

#include "transfer.h"

#include "../settings.h"
#include "../model/display.h"

static byte channel_pins[] = INPUT_CHANNELS;

static void latch(byte channelId) {
    digitalWrite(channel_pins[channelId], HIGH);
    digitalWrite(INPUT_LATCH_PIN, HIGH);
    delayMicroseconds(20);
    digitalWrite(INPUT_LATCH_PIN, LOW);
    digitalWrite(channel_pins[channelId], LOW);
}


bool Transfer::transfer(uint16_t* display, uint16_t* buttons) {
    digitalWrite(OUTPUT_LATCH_PIN, LOW);

    bool dirty = false;

    for (int8_t i = 3; i >= 0; i--) {
        latch(i);
        uint16_t data = SPI.transfer16(display[i]);
        dirty |= data != buttons[i];
        buttons[i] = data;
    }

    digitalWrite(OUTPUT_LATCH_PIN, HIGH);

    return dirty;
}

void Transfer::init() {
    digitalWrite(OUTPUT_LATCH_PIN, LOW);
    pinMode(OUTPUT_LATCH_PIN, OUTPUT);

    for (int i = 0; i < 4; i++) {
        digitalWrite(channel_pins[i], LOW);
        pinMode(channel_pins[i], OUTPUT);
    }
    digitalWrite(INPUT_LATCH_PIN, LOW);
    pinMode(INPUT_LATCH_PIN, OUTPUT);

    SPI.begin();
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

    SPI.transfer16(0x0000);
    SPI.transfer16(0x0000);
    SPI.transfer16(0x0000);

    digitalWrite(OUTPUT_LATCH_PIN, HIGH);
    digitalWrite(OUTPUT_ENABLE_PIN, LOW);
    pinMode(OUTPUT_ENABLE_PIN, OUTPUT);
}