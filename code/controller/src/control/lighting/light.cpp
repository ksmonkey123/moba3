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

static ButtonEdge button_start (BUTTON_KEYBOARD_03);
static ButtonEdge button_prev  (BUTTON_KEYBOARD_04);
static ButtonEdge button_next  (BUTTON_KEYBOARD_05);

static void singleLightBrowser() {
    static byte lightId = 0x10;

    if (button_start.test()) {
        if (lightId != 0x10) {
            Lights::setPin(lightId, false);
            lightId = 0x10;
        }
        Lights::setPin(lightId, true);
    } else if (button_prev.test()) {
        Lights::setPin(lightId, false);
        if (--lightId < 0x10) {
            lightId = (LIGHT_DECODER_COUNT * 0x10) + 0x0f;
        }
        Lights::setPin(lightId, true);
    } else if (button_next.test()) {
        Lights::setPin(lightId, false);
        if (++lightId >= (LIGHT_DECODER_COUNT + 1) * 0x10) {
            lightId = 0x10;
        }
        Lights::setPin(lightId, true);
    }
}
