#include "control_modules.h"

static void process(Timer*);

enum Entry { NONE, LEFT, RIGHT};

static byte currentTrack = -1;
static Entry currentEntry = NONE;

void Yard::init() {
    Timer::create(process)->start();
}

static void doReset() {
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

static void calculateBackSwitches(byte track) {
    Switches::setSwitch(SWITCH_YARD_11, track == 4 ? Switches::DIVERGING : Switches::STRAIGHT);
    if (track < 4) {
        Switches::setSwitch(SWITCH_YARD_12, track == 3 ? Switches::DIVERGING : Switches::STRAIGHT);
        if (track < 3) {
            Switches::setSwitch(SWITCH_YARD_13, track == 2 ? Switches::DIVERGING : Switches::STRAIGHT);
        }
    }
}

static boolean calculateSwitches(byte entry, byte track) {
    if (track == 1) {
        Switches::setSwitch(SWITCH_YARD_09, Switches::DIVERGING);
        Switches::setSwitch(SWITCH_YARD_10, Switches::DIVERGING);
    } else if (track == 2) {
        Switches::setSwitch(SWITCH_YARD_09, Switches::STRAIGHT);
    }
    boolean throughTrack = track > 0 && track < 5;
    if (entry == 0) {
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
            Switches::setSwitch(SWITCH_YARD_03, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_YARD_04, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_YARD_05, track == 9 ? Switches::STRAIGHT : Switches::DIVERGING);
            if (track < 9) {
                Switches::setSwitch(SWITCH_YARD_06, track == 7 ? Switches::STRAIGHT : Switches::DIVERGING);
            }
        }
        if (throughTrack) {
            calculateBackSwitches(track);
        }
    } else {
        // right entry
        if (!throughTrack) {
            return false;
        }
        Switches::setSwitch(SWITCH_YARD_01, Switches::DIVERGING);
        calculateBackSwitches(track); 
    }
    return true;
}

static void process(Timer*) {
    if (Buttons::read(BUTTON_YARD_CL)) {
        doReset();
        return;
    }

    byte trackButtons[12] = {
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
    
    byte entry, track;
    if (Buttons::readList(trackButtons, 12, &entry, &track) == 2) {
        if (entry > 1 || track < 2) {
            return;
        }

        // track button indices are shifted by 2 places since indices 0 and 1 are the entry buttons
        track -= 2;

        if (calculateSwitches(entry, track)) {
            calculateOutput(entry, track);
        }
    }

}
