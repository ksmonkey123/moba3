#include "switches.h"
#include "../settings.h"

static struct SwitchModel {
    struct SwitchDecoderState {
        struct SwitchStatus {
            Switches::STATUS selected;
            boolean dirty;
        } channel[6];
        boolean dirty;
    } decoder[SWITCH_DECODER_COUNT];
} model;

void Switches::setSwitch(byte id, Switches::STATUS status) {
    byte decoder = ((id & 0x70) >> 4) - 1;
    byte channel = (id & 0x07);

    SwitchModel::SwitchDecoderState* dec = model.decoder + decoder;
    SwitchModel::SwitchDecoderState::SwitchStatus* sw = dec->channel + channel;

    if (sw->selected != status) {
        sw->selected = status;
        sw->dirty = true;
        dec->dirty = true;
    }
}

void Switches::getNextCommand(char* buffer) {
    for(byte i = 0; i < SWITCH_DECODER_COUNT; i++) {
        auto dec = model.decoder + i;
        if (dec->dirty) {
            buffer[0] = 'W';
            buffer[1] = '1' + i;
            byte index = 2;
            for(byte j = 0; j < 6; j++) {
                auto sw = dec->channel + j;
                if (sw->dirty) {
                    buffer[index++] = '0' + j;
                    buffer[index++] = sw->selected;
                    sw->dirty = false;
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
