#include "buttons.h"
#include "utils.h"

Buttons::ButtonModel _buttons = {};

void Buttons::init() {
    memset(&_buttons, 0, sizeof(Buttons::ButtonModel));
}

void Buttons::processInput(char* buffer) {
    if (buffer[0] == 'X' && buffer[1] == 'X' && buffer[2] == 'X') {
        Buttons::init();
        return;
    }

    if (buffer[0] < 'A' || buffer[0] > 'E') {
        return;
    }

    Buttons::ButtonSector* sector = &_buttons.sector[buffer[0] - 'A'];
    auto id = Util::decodeHexString(buffer + 1, 1);
    auto direction = buffer[2];

    if (id == -1 || (direction != '+' && direction != '-')) {
        return;
    }

    sector->button[id] = direction == '+';
}
