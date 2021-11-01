#include "control_modules.h"
#include "../output/display.h"

void Darkmode::tick() {
    static boolean fired = false;
    boolean button = Buttons::read(BUTTON_DARKMODE);

    if (button && !fired) {
        Display::toggleDarkmode();
    }

    fired = button;
}
