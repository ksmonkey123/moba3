#include "control_modules.h"

void ForcedUpd::tick() {
    return;
    static bool state = false;
    bool newState = Buttons::read(BUTTON_SWITCHES_DISABLED);
    
    if (state == newState) {
        return;
    }

    state = newState;

    if (!state) {
        Switches::sendForcedUpdates();
    }
}
