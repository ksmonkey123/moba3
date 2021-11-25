#include "utils.h"

union raw16 {
    uint16_t value;
    uint8_t raw[2];
};

static void swap(uint8_t* x, uint8_t* y) {
    uint8_t temp = *x;
    *x = *y;
    *y = temp;
};

uint16_t Util::decodeHexString16(char* string) {
    static raw16 container;

    container.value = 0;

    for(byte i = 0; i < 4; i++) {
        container.value *= 16;
        char digit = string[i];
        if (digit >= '0' && digit <= '9') {
            container.value += (digit - '0');
        } else if (digit >= 'a' && digit <= 'f') {
            container.value += (digit - 'a' + 10);
        } else {
            return 0;
        }
    }

    swap(container.raw, container.raw + 1);

    return container.value;
}
