#include "control_modules.h"

static void process(Timer*);

enum Entry { NONE, LEFT, RIGHT};

static byte currentTrack = -1;
static Entry currentEntry = NONE;

void Yard::init() {
    Timer::create(10000, process)->start();
}

static void calculateOutput(byte direction, byte track) {
    Display::set(1, direction == 0 ? 0x04 : 0x18, 0x1c);

    if (track < 8) {
        Display::set(0, 0x01 << track, 0xff);
        Display::set(1, 0x00, 0x03);
    } else {
        Display::set(0, 0x00, 0xff);
        Display::set(1, 0x01 << (track - 8), 0x03);
    }
}

static void process(Timer*) {
    if (Buttons::read(BUTTON_YARD_CL)) {
        Switches::setSwitch(SWITCH_YARD_01, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_02, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_03, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_04, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_05, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_06, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_07, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_08, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_09, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_10, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_11, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_12, Switches::UNKNOWN);
        Switches::setSwitch(SWITCH_YARD_13, Switches::UNKNOWN);
        Display::set(0, 0x00, 0xff);
        Display::set(1, 0x00, 0x1f);
        return;
    }

    byte trackButtons[] = {
        BUTTON_YARD_L,
        BUTTON_YARD_R,
        BUTTON_YARD_01,
        BUTTON_YARD_02,
        BUTTON_YARD_03,
        BUTTON_YARD_04,
        BUTTON_YARD_05,
        BUTTON_YARD_06,
        BUTTON_YARD_07,
        BUTTON_YARD_08,
        BUTTON_YARD_09,
        BUTTON_YARD_10
    };
    
    byte first;
    byte second;

    if (Buttons::readList(trackButtons, 12, &first, &second) == 2) {
        if (first > 1 || second < 2) {
            return;
        }

        byte track = second - 2;

        if (track == 1) {
            Switches::setSwitch(SWITCH_YARD_09, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_YARD_10, Switches::DIVERGING);
        } else if (track == 2) {
            Switches::setSwitch(SWITCH_YARD_09, Switches::STRAIGHT);
        }

        if (first == 0) {
            // left entry
            Switches::setSwitch(SWITCH_YARD_01, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_YARD_02, track < 3 ? Switches::STRAIGHT : Switches::DIVERGING);
            if (track == 0) {
                Switches::setSwitch(SWITCH_YARD_10, Switches::STRAIGHT);
                Switches::setSwitch(SWITCH_YARD_09, Switches::DIVERGING);
            } else if (track > 2 && track < 7) {
                Switches::setSwitch(SWITCH_YARD_03, Switches::STRAIGHT);
                Switches::setSwitch(SWITCH_YARD_04, track == 3 ? Switches::DIVERGING : Switches::STRAIGHT);
                if (track > 3) {
                    Switches::setSwitch(SWITCH_YARD_07, track == 4 ? Switches::DIVERGING : Switches::STRAIGHT);
                    if (track > 4) {
                        Switches::setSwitch(SWITCH_YARD_08, track == 5 ? Switches::DIVERGING : Switches::STRAIGHT);
                    }
                }
            } else if (track >= 7) {
                Switches::setSwitch(BUTTON_YARD_03, Switches::STRAIGHT);
                Switches::setSwitch(BUTTON_YARD_04, Switches::STRAIGHT);
                Switches::setSwitch(BUTTON_YARD_05, track == 9 ? Switches::STRAIGHT : Switches::DIVERGING);
                if (track < 9) {
                    Switches::setSwitch(SWITCH_YARD_06, track == 7 ? Switches::STRAIGHT : Switches::DIVERGING);
                }
            }
        } else {
            // right entry
            if (track == 0 || track > 4) {
                return;
            }
            Switches::setSwitch(SWITCH_YARD_01, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_YARD_11, track == 4 ? Switches::DIVERGING : Switches::STRAIGHT);
            if (track < 4) {
                Switches::setSwitch(SWITCH_YARD_12, track == 3 ? Switches::DIVERGING : Switches::STRAIGHT);
                if (track < 3) {
                    Switches::setSwitch(SWITCH_YARD_13, track == 2 ? Switches::DIVERGING : Switches::STRAIGHT);
                }
            } 
        }

        calculateOutput(first, track);
    }

}
