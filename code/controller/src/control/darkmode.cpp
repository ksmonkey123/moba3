#include "control_modules.h"
#include "../output/display.h"

static void process(Timer*);

void Darkmode::init() {
    #ifdef DEBUG_LOG
    Serial.println("init darkmode controller");
    #endif
    Timer::create(process)->start();
}

static void process(Timer*) {
    static boolean fired = false;
    boolean button = Buttons::read(BUTTON_DARKMODE);

    if (button && !fired) {
        Display::toggleDarkmode();
    }

    fired = button;
}