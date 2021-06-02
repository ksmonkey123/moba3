#include "display.h"
#include <Arduino.h>

#include "../utils.h"

static struct Data {
    byte sector[6];
    boolean dirty;
} _data;

void Display::set(byte sector, byte data, byte mask) {
    byte x = _data.sector[sector];
    // clear masked bits, then merge in new data
    x &= (0xff ^ mask);
    x |= (data & mask);

    if (_data.sector[sector] != x) {
        _data.sector[sector] = x;
        _data.dirty = true;
    }
}

void Display::getNextCommand(char* buffer) {
    if (!_data.dirty) {
        buffer[0] = '\0';
        return;
    }
    buffer[0] = 'D';
    byte index = 1;
    for (byte i = 0; i < 6; i++) {
        Util::byteToHex(_data.sector[i], buffer + index);
        index += 2;
    }
    buffer[index] = '\n';
    _data.dirty = false;
}
