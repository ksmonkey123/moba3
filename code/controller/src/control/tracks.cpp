#include <Arduino.h>
#include "tracks.h"

#include "../input/buttons.h"
#include "../output/switches.h"
#include "../output/switchMapping.h"
#include "../timer.h"

void process();

static Timer timer = Timer(10000, process);

void Tracks::tick() {
    timer.tick();
}

void process() {
    if (_buttons.sector[1].button[0]) {
        // TODO: clear I/O
        return;
    }

    // process simple
    if (_buttons.sector[1].button[1] == true) Switches::setSwitch(SWITCH_TRACK_1, Switches::DIVERGING);
    if (_buttons.sector[1].button[2] == true) Switches::setSwitch(SWITCH_TRACK_1, Switches::STRAIGHT);
    if (_buttons.sector[1].button[3] == true) Switches::setSwitch(SWITCH_TRACK_2, Switches::STRAIGHT);
    if (_buttons.sector[1].button[4] == true) Switches::setSwitch(SWITCH_TRACK_2, Switches::DIVERGING);
    if (_buttons.sector[1].button[5] == true) Switches::setSwitch(SWITCH_TRACK_3, Switches::STRAIGHT);
    if (_buttons.sector[1].button[6] == true) Switches::setSwitch(SWITCH_TRACK_3, Switches::DIVERGING);
    if (_buttons.sector[1].button[7] == true) Switches::setSwitch(SWITCH_TRACK_4, Switches::DIVERGING);
    if (_buttons.sector[1].button[8] == true) Switches::setSwitch(SWITCH_TRACK_4, Switches::STRAIGHT);

    // process macros
    boolean button_1_or_2 = (_buttons.sector[1].button[1] || _buttons.sector[1].button[2]);
    boolean button_3_or_4 = (_buttons.sector[1].button[3] || _buttons.sector[1].button[4]);
    boolean button_7_or_8 = (_buttons.sector[1].button[7] || _buttons.sector[1].button[8]);
    
    if (button_7_or_8) {
        if (button_1_or_2 && !button_3_or_4) {
            Switches::setSwitch(SWITCH_TRACK_2, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_TRACK_3, Switches::DIVERGING);
        } else if (button_3_or_4 && !button_1_or_2) {
            Switches::setSwitch(SWITCH_TRACK_1, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_TRACK_3, Switches::STRAIGHT);
        }
    }
}
