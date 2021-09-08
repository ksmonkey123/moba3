#include "entrySignals.h"
#include "../settings.h"
#include "../macros.h"
#include "../statusLed.h"

static struct EntrySignalModel {
    struct EntrySignalDecoderState {
        struct SignalStatus {
            EntrySignals::STATUS primary;
            EntrySignals::STATUS secondary;
            boolean dirty;
        } channel[2];
        boolean dirty;
    } decoder[ENTRY_SIGNAL_DECODER_COUNT];
} model;

void EntrySignals::reset() {
    for (byte i = 0; i < ENTRY_SIGNAL_DECODER_COUNT; i++) {
        auto decoder = model.decoder + i;
        for (byte j = 0; j < 6; j++) {
            auto channel = decoder->channel + j;
            channel->primary = HALT;
            channel->secondary = HALT;
            channel->dirty = false;
        }
        decoder->dirty = false;
    }
}

void EntrySignals::setSignal(byte id, EntrySignals::STATUS primary, EntrySignals::STATUS secondary) {
    byte decoder = ((id & 0x70) >> 4) - 1;
    byte channel = (id & 0x07) - 1;

    auto dec = model.decoder + decoder;
    auto sig = dec->channel + channel;

    if (sig->primary != primary || sig->secondary != secondary) {
        sig->primary = primary;
        sig->secondary = secondary;
        sig->dirty = true;
        dec->dirty = true;
        StatusLED::blink;
    }
}

void EntrySignals::getNextCommand(char* buffer) {
    for(byte i = 0; i < ENTRY_SIGNAL_DECODER_COUNT; i++) {
        auto dec = model.decoder + i;
        if (dec->dirty) {
            buffer[0] = 'E';
            buffer[1] = '1' + i;
            byte index = 2;
            for(byte j = 0; j < 2; j++) {
                auto sig = dec->channel + j;
                if (sig->dirty) {
                    buffer[index++] = 'a' + j;
                    buffer[index++] = '0' + sig->primary;
                    buffer[index++] = '0' + sig->secondary;
                    sig->dirty = false;
                }
            }
            buffer[index++] = '\n';
            buffer[index] = 0;
            dec->dirty = false;
            return;
        }
    }
    // none dirty
    buffer[0] = 0;
}

void EntrySignals::getRepetitionCommand(char* buffer) {
    static byte decoderId = 0;

    RETRANSMIT_GUARD()

    auto dec = model.decoder + decoderId;
    buffer[0] = 'E';
    buffer[1] = '1' + decoderId;
    byte index = 2;
    for(byte j = 0; j < 2; j++) {
        auto sig = dec->channel + j;
        buffer[index++] = 'a' + j;
        buffer[index++] = '0' + sig->primary;
        buffer[index++] = '0' + sig->secondary;
    }
    buffer[index++] = '\n';
    buffer[index++] = '\0';
    
    NEXTVAL(decoderId, ENTRY_SIGNAL_DECODER_COUNT)
}
