#include "exitSignals.h"
#include "../settings.h"
#include "../statusLed.h"
#include "../utils.h"

static struct ExitSignalModel {
    struct ExitSignalDecoderState {
        byte data;
        boolean dirty;
    } decoder[EXIT_SIGNAL_DECODER_COUNT];
} model;

void ExitSignals::reset() {
    for (byte i = 0; i < EXIT_SIGNAL_DECODER_COUNT; i++) {
        auto decoder = model.decoder + i;
        decoder->data = 0;
        decoder->dirty = false;
    }
}

void ExitSignals::setSignal(byte id, byte data, byte mask) {
    auto dec = model.decoder + id - 1;

    byte newData = data & (mask ^ 0xff);
    newData |= (data & mask);

    if (dec->data != newData) {
        dec->data = newData;
        dec->dirty = true;
        StatusLED::blink;
    }
}

void ExitSignals::getNextCommand(char* buffer) {
    for(byte i = 0; i < EXIT_SIGNAL_DECODER_COUNT; i++) {
        auto dec = model.decoder + i;
        if (dec->dirty) {
            buffer[0] = 'A';
            buffer[1] = '1' + i;
            buffer[2] = 's';
            Util::byteToHex(dec->data, buffer + 3);
            buffer[5] = '\n';
            buffer[6] = '\0';

            dec->dirty = false;
            return;
        }
    }
    // none dirty
    buffer[0] = 0;
}
