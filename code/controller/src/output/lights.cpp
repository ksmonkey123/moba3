#include "lights.h"
#include "../settings.h"
#include "../statusLed.h"
#include "../utils.h"
#include "../macros.h"

static struct LightsModel {
    struct LightDecoderState {
        union LightDecoderData {
            uint16_t value;
            uint8_t raw[2];
        } state;
        boolean dirty;
    } decoder[LIGHT_DECODER_COUNT];
} model;

void Lights::setPin(uint8_t id, boolean on) {
    byte decoder = ((id & 0x70) >> 4) - 1;
    byte pin = id & 0x0f;
    uint16_t mask = 0x0001 << pin;

    auto dec = model.decoder + decoder;

    uint16_t state = dec->state.value;
    state &= (0xffff ^ mask);
    if (on) {
        state |= mask;
    }

    if (dec->state.value != state) {
        dec->state.value = state;
        dec->dirty = true;
        StatusLED::blink;
    }
}

static void generateCommand(byte decoderId, char* buffer) {
    buffer[0] = 'L';
    buffer[1] = '1' + decoderId;

    auto decoder = model.decoder + decoderId;

    Util::byteToHex(decoder->state.raw[0], buffer + 2);
    Util::byteToHex(decoder->state.raw[1], buffer + 4);

    buffer[6] = '\n';
    buffer[7] = '\0';
}

void Lights::getNextCommand(char* buffer) {
    for(byte i = 0; i < LIGHT_DECODER_COUNT; i++) {
        auto dec = model.decoder + i;
        if (dec->dirty) {
            generateCommand(i, buffer);
            dec->dirty = false;
            return;
        }
    }
    // none dirty
    buffer[0] = '\0';
}

void Lights::getRepetitionCommand(char* buffer) {
    static byte decoderId = 0;

    RETRANSMIT_GUARD()

    generateCommand(decoderId, buffer);
    
    NEXTVAL(decoderId, LIGHT_DECODER_COUNT)
}
