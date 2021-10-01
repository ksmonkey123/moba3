#include "exitSignals.h"
#include "../settings.h"
#include "../statusLed.h"
#include "../utils.h"
#include "../macros.h"

static struct ExitSignalModel {
    struct ExitSignalDecoderState {
        SignalLevel channel[4];
        boolean dirty;
    } decoder[EXIT_SIGNAL_DECODER_COUNT];
} model;

void ExitSignals::reset() {
    for (byte i = 0; i < EXIT_SIGNAL_DECODER_COUNT; i++) {
        auto decoder = model.decoder + i;
        for (byte j = 0; j < 4; j++) {
            decoder->channel[j] = HALT;
        }
        decoder->dirty = false;
    }
}

void ExitSignals::setSignal(byte chipAddress, byte channelId, SignalLevel level) {
    auto dec = model.decoder + chipAddress - 1;
    auto channel = dec->channel + channelId;

    if (*channel != level) {
        *channel = level;
        dec->dirty = true;
        StatusLED::blink();
    }
}

static void generateCommand(byte decoderId, char* buffer) {
    buffer[0] = 'A';
    buffer[1] = '1' + decoderId;

    auto decoder = model.decoder + decoderId;

    byte index = 2;
    for (byte i = 0; i < 4; i++) {
        buffer[index++] = 'a' + i;
        buffer[index++] = '0' + decoder->channel[i];
    }

    buffer[index++] = '\n';
    buffer[index] = '\0';
}

void ExitSignals::getNextCommand(char* buffer) {
    for(byte i = 0; i < EXIT_SIGNAL_DECODER_COUNT; i++) {
        auto dec = model.decoder + i;
        if (dec->dirty) {
            generateCommand(i, buffer);
            dec->dirty = false;
            return;
        }
    }
    // none dirty
    buffer[0] = 0;
}

void ExitSignals::getRepetitionCommand(char* buffer) {
    static byte decoderId = 0;

    RETRANSMIT_GUARD()

    generateCommand(decoderId, buffer);
    
    NEXTVAL(decoderId, EXIT_SIGNAL_DECODER_COUNT)
}
