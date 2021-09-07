#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

namespace Util {
    unsigned long decodeHexString(char* string, char length);
    /**
     * convert a single byte of data to the 2-character hex representation.
     * 
     * @param data the raw byte to parse
     * @param buffer the output buffer. needs at least 2 bytes of space.
     */
    void byteToHex(byte data, char* buffer);
}

#endif
