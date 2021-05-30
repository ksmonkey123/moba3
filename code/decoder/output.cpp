#include <Arduino.h>
#include <SPI.h>

#include "settings.h"
#include "output.h"

static uint16_t state;
static Output::Config config;

void send(uint16_t data) {
    digitalWrite(OUTPUT_LATCH_PIN, LOW);
    if (config.inverted) {
        data ^= 0xffff;
    }
    SPI.transfer16(data & config.mask);
    digitalWrite(OUTPUT_LATCH_PIN, HIGH);
}

void Output::init(uint16_t data, Config* __config) {
    if (__config == nullptr) {
        memset(&config, 0, sizeof(Config));
        config.mask = 0xffff;
    } else {
        memcpy(&config, __config, sizeof(Config));
    }

    digitalWrite(OUTPUT_LATCH_PIN, LOW);
    pinMode(OUTPUT_LATCH_PIN, OUTPUT);
    static boolean spiStarted = false;
    if (!spiStarted) {
        spiStarted = true;
        SPI.begin();
        SPI.beginTransaction(OUTPUT_SPI_SETTINGS);
    }
    send(data);
    state = data;
    digitalWrite(OUTPUT_ENABLE_PIN, LOW);
    pinMode(OUTPUT_ENABLE_PIN, OUTPUT);
}

void Output::clear() {
    state = 0;
    send(0);
}

void Output::fill() {
    state = -1;
    send(-1);
}

void Output::setMask(uint16_t data) {
    state |= data;
    send(state);
}

void Output::clearMask(uint16_t data) {
    state &= (-1 ^ data);
    send(state);
}

void Output::setState(uint16_t data){
    state = data;
    send(state);
}
