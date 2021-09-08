#include "switches.h"
#include "../settings.h"
#include "../statusLed.h"

static struct SwitchModel {
    struct SwitchDecoderState {
        struct SwitchStatus {
            Switches::STATUS selected;
            boolean dirty;
        } channel[6];
        boolean dirty;
    } decoder[SWITCH_DECODER_COUNT];
    boolean dirty;
    struct ForcedUpdate {
        Switches::ForcedUpdateState state;
        byte decoder;
        byte channel;
    } forcedUpdate;
} model;

void Switches::sendForcedUpdates() {
    model.forcedUpdate.state = ARMED;
    model.forcedUpdate.channel = 0;
    model.forcedUpdate.decoder = 0;
}

void Switches::reset() {
    for (byte i = 0; i < SWITCH_DECODER_COUNT; i++) {
        auto decoder = model.decoder + i;
        for (byte j = 0; j < 6; j++) {
            auto channel = decoder->channel + j;
            channel->selected = UNKNOWN;
            channel->dirty = false;
        }
        decoder->dirty = false;
    }
    model.dirty = false;
}

void Switches::setSwitch(byte id, Switches::STATUS status) {
    byte decoder = ((id & 0x70) >> 4) - 1;
    byte channel = (id & 0x07) - 1;

    auto dec = model.decoder + decoder;
    auto sw = dec->channel + channel;

    if (sw->selected != status) {
        sw->selected = status;
        if (status != Switches::UNKNOWN) {
            sw->dirty = true;
            dec->dirty = true;
            model.dirty = true;
            StatusLED::blink();
        }
    }
}

static void nextFullCommand(char* buffer) {
    for(byte i = 0; i < SWITCH_DECODER_COUNT; i++) {
        auto dec = model.decoder + i;
        if (dec->dirty) {
            buffer[0] = 'W';
            buffer[1] = '1' + i;
            byte index = 2;
            for(byte j = 0; j < 6; j++) {
                auto sw = dec->channel + j;
                if (sw->dirty) {
                    buffer[index++] = '1' + j;
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

static void getNormalCommand(char* buffer) {
    static unsigned long lastCall = 0;
    if (lastCall + SWITCH_STAGGERING_PERIOD > millis()) {
        // last call was too recent
        return;
    }

    for (byte i = 0; i < SWITCH_DECODER_COUNT; i++) {
        auto dec = model.decoder + i;
        if (!dec->dirty) {
            continue;
        }

        // decoder is dirty
        SwitchModel::SwitchDecoderState::SwitchStatus* sw = nullptr;
        byte j = 0;
        for (; j < 6; j++) {
            auto s = dec->channel + j;
            if (s->dirty) {
                sw = s;
                break;
            }
        }
        if (sw == nullptr) {
            // decoder was wrongfully marked as dirty
            dec->dirty = false;
            continue;
        }

        // we have a dirty switch
        buffer[0] = 'W';
        buffer[1] = '1' + i;
        buffer[2] = '1' + j;
        buffer[3] = sw->selected;
        buffer[4] = '\n';
        buffer[5] = '\0';

        // clean up dirty state
        lastCall = millis();
        sw->dirty = false;

        for (; j < 6; j++) {
            if((dec->channel + j)->dirty) {
                // there are dirty switches left
                return;
            }
        }
        
        dec->dirty = false;
        return;
    }
    model.dirty = false;
}

static void getForcedUpdateCommand(char* buffer) {
    static unsigned long lastCall = 0;
    if (lastCall + SWITCH_STAGGERING_PERIOD > millis()) {
        // last call was too recent
        return;
    }
    lastCall = millis();

    if (model.forcedUpdate.state == Switches::ARMED) {
        model.forcedUpdate.state = Switches::RUNNING;
        return;
    }

    byte* decoder = &model.forcedUpdate.decoder;
    byte* channel = &model.forcedUpdate.channel;

    buffer[0] = 'W';
    buffer[1] = '1' + *decoder;
    buffer[2] = '1' + *channel;
    buffer[3] = '!';
    buffer[4] = '\n';
    buffer[5] = '\0';

    if (++*channel == 6) {
        *channel = 0;
        if (++*decoder == SWITCH_DECODER_COUNT) {
            *decoder = 0;
            model.forcedUpdate.state = Switches::IDLE;
        }
    }
}

void Switches::getNextCommand(char* buffer) {
    buffer[0] = '\0';

    if (model.forcedUpdate.state != IDLE) {
        getForcedUpdateCommand(buffer);
    } else if (model.dirty) {
        getNormalCommand(buffer);
    }

}
