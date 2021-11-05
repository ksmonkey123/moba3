#include "utils.h"

#include <Arduino.h>

byte Util::decodeHexNibble(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else {
        return 0xff;
    }
}

char nibble2hex(byte data) {
    if (data < 10) {
        return '0' + data;
    } else {
        return 'a' + (data - 10);
    }
}

void Util::byteToHex(byte data, char* buffer) {
    buffer[0] = nibble2hex((data >> 4) & 0x0f);
    buffer[1] = nibble2hex(data & 0x0f);
}
