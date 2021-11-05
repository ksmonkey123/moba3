#include <Arduino.h>
#include "buttons.h"
#include "../settings.h"
#include "../utils.h"
#include "../output/switches.h"
#include "../async.h"

/** a single 16-bit button sector */
struct ButtonSector {
    boolean button[16];
};

/** the internal model */
struct ButtonModel {
    ButtonSector sector[4];
};

static ButtonModel _buttons;

void Buttons::init() {
    memset(&_buttons, 0, sizeof(ButtonModel));
}

static uint8_t pulsedId;

static void disablePulsed() {
    ButtonSector* sector = &_buttons.sector[(pulsedId >> 4) & 0x0f];
    sector->button[pulsedId & 0x0f] = false;
}

void Buttons::processInput(char* buffer) {
    if (buffer[0] == 'X' && buffer[1] == 'X' && buffer[2] == 'X') {
        Serial.println("RESET");
        Buttons::init();
        Switches::reset();
        return;
    }

    if (buffer[0] == '-' && buffer[1] == '-' && buffer[2] == '-') {
        Buttons::init();
    }

    if (buffer[0] < '0' || buffer[0] > '3') {
        return;
    }

    auto sectorId = buffer[0] - '0';
    ButtonSector* sector = &_buttons.sector[sectorId];
    auto id = Util::decodeHexString(buffer + 1, 1);
    auto direction = buffer[2];

    if (id == -1 || (direction != '+' && direction != '-' && direction != '*')) {
        return;
    }

    if (direction == '*') {
        pulsedId = ((sectorId << 4) & 0xf0) + (id & 0x0f);
        sector->button[id] = true;
        async(disablePulsed, 500);
    } else {
        sector->button[id] = direction == '+';
    }
}

boolean Buttons::read(byte id) {
    byte sector = (id >> 4) & 0x0f;
    byte button = id & 0x0f;

    return _buttons.sector[sector].button[button];
}

byte Buttons::readList(byte* buttons, byte len, byte* firstIndex, byte* lastIndex) {
    byte count = 0;
    for (byte i = 0; i < len; i++) {
        if (Buttons::read(buttons[i])) {
            count++;
            buttons[i] = 1;
            if (count == 1 && firstIndex != nullptr) {
                *firstIndex = i;
            }
            if (lastIndex != nullptr) {
                *lastIndex = i;
            }
        } else {
            buttons[i] = 0;
        }
    }
    return count;
}
