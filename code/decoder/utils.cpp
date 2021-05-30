#include "utils.h"

unsigned long Util::decodeHexString(char* string, char length) {
    unsigned long x = 0;
    for(char i = 0; i < length; i++) {
        x *= 16;
        char digit = string[i];
        if (digit >= '0' && digit <= '9') {
            x += (digit - '0');
        } else if (digit >= 'a' && digit <= 'f') {
            x += (digit - 'a' + 10);
        } else {
            return 0;
        }
    }
    return x;
}