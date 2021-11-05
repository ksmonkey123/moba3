#include "lights.h"
#include "../settings.h"
#include "../statusLed.h"
#include "../utils.h"
#include "../macros.h"

static struct LightsModel {
    struct LightDecoderState {
        Util::Raw16 state;
        uint16_t dirt_mask;
    } decoder[LIGHT_DECODER_COUNT];
    boolean dirty;
} model;

void Lights::setPin(uint8_t id, boolean on) {
    byte decoder = ((id & 0x70) >> 4) - 1;
    byte pin = id & 0x0f;
    uint16_t mask = 0x0001 << pin;

    auto dec = model.decoder + decoder;

    // calculate new value data value
    uint16_t state = dec->state.value;
    state &= (0xffff ^ mask);
    if (on) {
        state |= mask;
    }

    // update model & dirty flags
    if (dec->state.value != state) {
        dec->state.value = state;
        dec->dirt_mask |= mask;
        model.dirty = true;
        StatusLED::blink();
    }
}

static void updateGlobalDirtyFlag() {
    for (byte i = 0; i < LIGHT_DECODER_COUNT; i++) {
        if (model.decoder[i].dirt_mask != 0) {
            model.dirty = true;
            return;
        }
    }
    // no decoder is dirty, clear global flag.
    model.dirty = false;
}

static void nextCommand(char* buffer) {
    static unsigned long lastCall = 0;
    if (lastCall + LIGHT_STAGGERING_PERIOD > millis()) {
        // last call was too recent
        return;
    }
    lastCall = millis();

    // randomly choose a decoder
    uint8_t decId;
    do {
        decId = random(0, LIGHT_DECODER_COUNT);
    } while (model.decoder[decId].dirt_mask == 0);
    auto decoder = model.decoder + decId;

    // randomly choose a dirty pin on the decoder
    Util::Raw16 mask;
    do {
        auto pinId = random(0, 16);
        mask.value = 0x0001 << pinId;
    } while ((decoder->dirt_mask & mask.value) == 0);
    boolean state = (decoder->state.value & mask.value) != 0;

    // clear dirt mask
    decoder->dirt_mask ^= mask.value;
    updateGlobalDirtyFlag();

    // generate command
    buffer[0] = 'L';
    buffer[1] = '1' + decId;
    buffer[2] = state ? 's' : 'c';

    Util::byteToHex(mask.raw[0], buffer + 3);
    Util::byteToHex(mask.raw[1], buffer + 5);

    buffer[7] = '\n';
    buffer[8] = '\0';
}

void Lights::getNextCommand(char* buffer) {
    buffer[0] = '\0';
    
    if (model.dirty) {
        nextCommand(buffer);
    }
}

void Lights::getRepetitionCommand(char* buffer) {
    static byte decoderId = 0;

    if (model.dirty) {
        // suppress repetition when model is dirty
        return;
    }

    RETRANSMIT_GUARD()
    
    buffer[0] = 'L';
    buffer[1] = '1' + decoderId;
    buffer[2] = 'u';

    auto decoder = model.decoder + decoderId;

    Util::byteToHex(decoder->state.raw[0], buffer + 3);
    Util::byteToHex(decoder->state.raw[1], buffer + 5);

    buffer[7] = '\n';
    buffer[8] = '\0';

    NEXTVAL(decoderId, LIGHT_DECODER_COUNT)
}
