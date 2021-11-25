#include "utils.h"

#include <Arduino.h>

unsigned long Util::decodeHexString(char* string, char length) {
    unsigned long x = 0;
    for(byte i = 0; i < length; i++) {
        x *= 16;
        char digit = string[i];
        if (digit >= '0' && digit <= '9') {
            x += (digit - '0');
        } else if (digit >= 'a' && digit <= 'f') {
            x += (digit - 'a' + 10);
        } else {
            return -1;
        }
    }
    return x;
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
