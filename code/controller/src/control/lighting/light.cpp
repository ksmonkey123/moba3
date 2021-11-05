#include "../control_modules.h"

static void fullUpdate();
static void singleLightBrowser();

void Light::tick() {
    fullUpdate();
    singleLightBrowser();
}

static void fullUpdate() {
    boolean button_off = Buttons::read(BUTTON_KEYBOARD_01);
    boolean button_on  = Buttons::read(BUTTON_KEYBOARD_02);
    
    if (button_off == button_on) {
        return;
    }

    for (byte i = 0x10; i < (LIGHT_DECODER_COUNT + 1) * 0x10; i++) {
        Lights::setPin(i, button_on);
    }
}

static void singleLightBrowser() {
    static byte lightId = 0x10;
    static boolean fired = false;
    
    boolean button_start = Buttons::read(BUTTON_KEYBOARD_03);
    boolean button_prev  = Buttons::read(BUTTON_KEYBOARD_04);
    boolean button_next  = Buttons::read(BUTTON_KEYBOARD_05);

    if (fired) {
        fired = button_start | button_prev | button_next;
        if (fired) {
            return;
        }
    }

    if (button_start) {
        if (lightId != 0x10) {
            Lights::setPin(lightId, false);
            lightId = 0x10;
        }
        Lights::setPin(lightId, true);
    } else if (button_prev) {
        Lights::setPin(lightId, false);
        if (--lightId < 0x10) {
            lightId = (LIGHT_DECODER_COUNT * 0x10) + 0x0f;
        }
        Lights::setPin(lightId, true);
    } else if (button_next) {
        Lights::setPin(lightId, false);
        if (++lightId >= (LIGHT_DECODER_COUNT + 1) * 0x10) {
            lightId = 0x10;
        }
        Lights::setPin(lightId, true);
    } else {
        fired = false;
        return;
    }
    fired = true;
}
