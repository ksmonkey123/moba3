#include "control_modules.h"

static void process(Timer*);

void ForcedUpd::init() {
    Timer::create(SWITCH_FORCED_UPDATE_TIMER_PERIOD, process)->start();
}

static bool state = false;

static void process(Timer*) {
    bool newState = Buttons::read(BUTTON_SWITCHES_DISABLED);
    
    if (state == newState) {
        return;
    }

    state = newState;

    if (!state) {
        Switches::sendForcedUpdates();
    }
}
