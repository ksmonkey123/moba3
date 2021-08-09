#include "display.h"
#include <Arduino.h>

#include "../utils.h"
#include "../settings.h"
#include "../timer.h"

static struct Data {
    byte sector[6];
    boolean dirty;
    struct Darkmode {
        boolean active;
        boolean blanked;
        unsigned long lastChange;
    } darkmode;
} _data;

void Display::toggleDarkmode() {
    _data.darkmode.active = !_data.darkmode.active;
    set(1, _data.darkmode.active ? 0xff : 0x00, 0x80);
}

void Display::set(byte sector, byte data, byte mask) {
    byte x = _data.sector[sector];
    // clear masked bits, then merge in new data
    x &= (0xff ^ mask);
    x |= (data & mask);

    if (_data.sector[sector] != x) {
        _data.sector[sector] = x;
        _data.dirty = true;
        _data.darkmode.lastChange = micros();
    }
}

void Display::getNextCommand(char* buffer) {
    if (_data.dirty) {
        buffer[0] = 'D';
        byte index = 1;
        for (byte i = 0; i < 6; i++) {
            Util::byteToHex(_data.sector[i], buffer + index);
            index += 2;
        }
        buffer[index] = '\n';
        _data.dirty = false;
        _data.darkmode.blanked = false;
    } else {
        if (_data.darkmode.active && !_data.darkmode.blanked && micros() - _data.darkmode.lastChange > DARKMODE_TIMEOUT) {
            for (byte i = 1; i <= 12; i++) {
                buffer[i] = '0';
            }
            buffer[0] = 'D';
            buffer[3] = '8';
            buffer[13] = '\n';
            _data.darkmode.blanked = true;
        } else {
            buffer[0] = '\0';
        }
    }
}
