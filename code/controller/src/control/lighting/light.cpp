#include "../control_modules.h"

static void set(boolean on) {
    for (byte i = 0x10; i < (LIGHT_DECODER_COUNT + 1) * 0x10; i++) {
        Lights::setPin(i, on);
    }
}

void Light::tick() {
    boolean button_off = Buttons::read(BUTTON_KEYBOARD_01);
    boolean button_on  = Buttons::read(BUTTON_KEYBOARD_02);
    
    if (button_on && !button_off) {
        set(true);
    }
    if (!button_on && button_off) {
        set(false);
    }
}
