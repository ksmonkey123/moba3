#include "../control_modules.h"

void Tracks::tick() {
    if (Buttons::read(BUTTON_TRACK_C)) {
        Switches::setSwitch(SWITCH_TRACK_1, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_TRACK_2, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_TRACK_3, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_TRACK_4, Switches::UNKNOWN);
        Display::set(2, 0x00, 0xff);
        return;
    }

    boolean button_1 = Buttons::read(BUTTON_TRACK_1);
    boolean button_2 = Buttons::read(BUTTON_TRACK_2);
    boolean button_3 = Buttons::read(BUTTON_TRACK_3);
    boolean button_4 = Buttons::read(BUTTON_TRACK_4);
    boolean button_5 = Buttons::read(BUTTON_TRACK_5);
    boolean button_6 = Buttons::read(BUTTON_TRACK_6);
    boolean button_7 = Buttons::read(BUTTON_TRACK_7);
    boolean button_8 = Buttons::read(BUTTON_TRACK_8);

    // process simple
    if (button_1 && !button_2) { 
        Switches::setSwitch(SWITCH_TRACK_1, Switches::DIVERGING);
        Display::set(2, 0x01, 0x03);
    }
    if (button_2 && !button_1) { 
        Switches::setSwitch(SWITCH_TRACK_1, Switches::STRAIGHT);
        Display::set(2, 0x02, 0x03);
    }
    if (button_3 && !button_4) { 
        Switches::setSwitch(SWITCH_TRACK_2, Switches::STRAIGHT);
        Display::set(2, 0x04, 0x0c);
    }    
    if (button_4 && !button_3) { 
        Switches::setSwitch(SWITCH_TRACK_2, Switches::DIVERGING);
        Display::set(2, 0x08, 0x0c);
    }
    if (button_5 && !button_6) { 
        Switches::setSwitch(SWITCH_TRACK_3, Switches::STRAIGHT);
        Display::set(2, 0x10, 0x30);
    }
    if (button_6 && !button_5) { 
        Switches::setSwitch(SWITCH_TRACK_3, Switches::DIVERGING);
        Display::set(2, 0x20, 0x30);
    }
    if (button_7 && !button_8) { 
        Switches::setSwitch(SWITCH_TRACK_4, Switches::DIVERGING);
        Display::set(2, 0x40, 0xc0);
    }
    if (button_8 && !button_7) { 
        Switches::setSwitch(SWITCH_TRACK_4, Switches::STRAIGHT);
        Display::set(2, 0x80, 0xc0);
    }
    // process macros
    boolean button_1_or_2 = button_1 || button_2;
    boolean button_3_or_4 = button_3 || button_4;
    boolean button_7_or_8 = button_7 || button_8;
    
    if (button_7_or_8) {
        if (button_1_or_2 && !button_3_or_4) {
            Switches::setSwitch(SWITCH_TRACK_2, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_TRACK_3, Switches::DIVERGING);
            Display::set(2, 0x24, 0x3c);
        } else if (button_3_or_4 && !button_1_or_2) {
            Switches::setSwitch(SWITCH_TRACK_1, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_TRACK_3, Switches::STRAIGHT);
            Display::set(2, 0x12, 0x33);
        }
    }
}
