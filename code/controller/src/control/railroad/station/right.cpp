#include "../../control_modules.h"
#include "station.h"

static void tick(Timer*);
static void upgrade(Timer*);

EntrySignals::STATUS exitSignalsRight[4];

struct Path {
    int8_t target;
    SignalDirection direction;
};

static Path innerPath = { .target = -1, .direction = SignalDirection::DISABLED };
static Path outerPath = { .target = -1, .direction = SignalDirection::DISABLED };

static Timer* upgradeTimer;

static struct {
    SignalDirection signalDirection;
    byte track;
    byte entry;
} data;

void Station::Right::init() {
    Timer::create(tick)->start();
    upgradeTimer = Timer::create(SIGNAL_UPGRADE_DELAY, upgrade);
}

static boolean isCrossed = false;

static void resetInner();
static void resetOuter();

static void resetInner() {
    innerPath.target = -1;
    Switches::setSwitch(SWITCH_RIGHT_1, Switches::UNKNOWN);
    Switches::setSwitch(SWITCH_RIGHT_4, Switches::UNKNOWN);
    Switches::setSwitch(SWITCH_RIGHT_5, Switches::UNKNOWN);
    EntrySignals::setSignal(ENTRY_SIGNAL_R_INNER, EntrySignals::HALT, EntrySignals::HALT);
    ExitSignals::setSignal(EXIT_SIGNALS_R, 0x00, 0x03);
    Display::set(4, 0x00, 0x0f);
    Display::set(5, 0x00, 0x30);
    if (isCrossed) {
        isCrossed = false;
        resetOuter();
    }
}

static void resetOuter() {
    outerPath.target = -1;
    Switches::setSwitch(SWITCH_RIGHT_2, Switches::UNKNOWN);
    Switches::setSwitch(SWITCH_RIGHT_3, Switches::UNKNOWN);
    Switches::setSwitch(SWITCH_RIGHT_6, Switches::UNKNOWN);
    EntrySignals::setSignal(ENTRY_SIGNAL_R_OUTER, EntrySignals::HALT, EntrySignals::HALT);
    ExitSignals::setSignal(EXIT_SIGNALS_R, 0x00, 0x1c);
    Display::set(4, 0x00, 0xf0);
    Display::set(5, 0x00, 0xc0);
    if (isCrossed) {
        isCrossed = false;
        resetInner();
    }
}

static boolean processSwitches(byte entry, byte track) {
    switch(entry * 16 + track) {
        // inner access
        case 0x00: {
            Switches::setSwitch(SWITCH_RIGHT_1, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_RIGHT_4, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_RIGHT_5, Switches::DIVERGING);
            return false;
        }
        case 0x01: {
            Switches::setSwitch(SWITCH_RIGHT_1, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_RIGHT_4, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_RIGHT_5, Switches::STRAIGHT);
            return false;
        }
        case 0x02: {
            Switches::setSwitch(SWITCH_RIGHT_1, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_2, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_RIGHT_3, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_6, Switches::DIVERGING);
            return true;
        }
        case 0x03: {
            Switches::setSwitch(SWITCH_RIGHT_1, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_2, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_RIGHT_3, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_6, Switches::DIVERGING);
            return true;
        }
        // outer access
        case 0x10: {
            Switches::setSwitch(SWITCH_RIGHT_2, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_3, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_RIGHT_4, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_5, Switches::DIVERGING);
            return true;
        }
        case 0x11: {
            Switches::setSwitch(SWITCH_RIGHT_2, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_3, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_RIGHT_4, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_5, Switches::STRAIGHT);
            return true;
        }
        case 0x12: {
            Switches::setSwitch(SWITCH_RIGHT_2, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_3, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_6, Switches::DIVERGING);
            return false;
        }
        case 0x13: {
            Switches::setSwitch(SWITCH_RIGHT_2, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_3, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_RIGHT_6, Switches::STRAIGHT);
            return false;
        }
        // all others are invalid
        default: {
            return false;
        }
    }
}

static void processDisplay() {
    byte sector_4 = 0x00;
    byte sector_5 = 0x00;

    // process inner path
    if (innerPath.target >= 0) {
        byte segment = innerPath.direction == DISABLED ? 0x03 : innerPath.direction == ENTRY ? 0x01 : 0x02;
        sector_4 |= segment << (innerPath.target * 2);
        if (segment != 0x03) {
            segment ^= 0x03;
        }
        sector_5 |= segment << 4;
    }
    // process outer path
    if (outerPath.target >= 0) {
        byte segment = outerPath.direction == DISABLED ? 0x03 : outerPath.direction == ENTRY ? 0x01 : 0x02;
        sector_4 |= segment << (outerPath.target * 2);
        if (segment != 0x03) {
            segment ^= 0x03;
        }
        sector_5 |= segment << 6;
    }

    // publish
    Display::set(4, sector_4, 0xff);
    Display::set(5, sector_5, 0xf0);

}

static void processExitSignal(byte exit, byte track, byte* data) {
    if (track == 3 && exit == 1) {
        exitSignalsRight[3] = EntrySignals::SLOW_60;
        *data |= 0x10;
    } else {
        exitSignalsRight[track] = EntrySignals::SLOW_40;
        *data |= 0x01 << track;
    }
}

void Station::Right::refreshSignals() {
    // build entry signals
    if (innerPath.target >= 0 && innerPath.direction == ENTRY) {
        EntrySignals::setSignal(ENTRY_SIGNAL_R_INNER, EntrySignals::SLOW_40, exitSignalsLeft[innerPath.target]);
    } else {
        EntrySignals::setSignal(ENTRY_SIGNAL_R_INNER, EntrySignals::HALT, EntrySignals::HALT);
    }

    if (outerPath.target >= 0 && outerPath.direction == ENTRY) {
        EntrySignals::setSignal(ENTRY_SIGNAL_R_OUTER, outerPath.target == 3 ? EntrySignals::SLOW_60 : EntrySignals::SLOW_40, exitSignalsLeft[outerPath.target]);
    } else {
        EntrySignals::setSignal(ENTRY_SIGNAL_R_OUTER, EntrySignals::HALT, EntrySignals::HALT);
    }
}

static void processSignals() {
    Station::Right::refreshSignals();

    // build exit signals
    memset(exitSignalsRight, 0, sizeof(exitSignalsRight));

    byte data = 0;
    if (innerPath.target >= 0 && innerPath.direction == EXIT) {
        processExitSignal(0, innerPath.target, &data);
    }
    if (outerPath.target >= 0 && outerPath.direction == EXIT) {
        processExitSignal(1, outerPath.target, &data);
    }

    ExitSignals::setSignal(EXIT_SIGNALS_R, data, 0x1f);
    Station::Left::refreshSignals();
}

static void processDisplayAndSignals() {
    processDisplay();
    processSignals();
}

static void tick(Timer*) {
    // handle reset
    boolean reset = false;
    if (Buttons::read(BUTTON_STATION_CLEAR_R_1)) {
        resetInner();
        reset = true;
    }
    if (Buttons::read(BUTTON_STATION_CLEAR_R_2)) {
        resetOuter();
        reset = true;
    }
    if (reset) {
        upgradeTimer->stop();
        return;
    }

    // process buttons
    byte buttons[] = {
        BUTTON_STATION_TRACK_1,
        BUTTON_STATION_TRACK_2,
        BUTTON_STATION_TRACK_3,
        BUTTON_STATION_TRACK_4,
        BUTTON_STATION_ENTRY_R_1,
        BUTTON_STATION_ENTRY_R_2,
    };

    byte track, entry;
    byte pressedCount = Buttons::readList(buttons, 6, &track, &entry);

    if (pressedCount == 1) {
        data.signalDirection = track < 4 ? EXIT : ENTRY;
    }
    if (pressedCount == 2) {
        if (track >= 4 || entry < 4) {
            return;
        }

        if (data.track == track && data.entry == (entry - 4)) {
            return;
        }

        data.track = track;
        data.entry = entry - 4;

        Path* path = entry == 4 ? &innerPath : &outerPath;
        path->target = track;
        path->direction = DISABLED;

        boolean wasCrossed = isCrossed;
        isCrossed = processSwitches(entry - 4, track);

        if (isCrossed) {
            // if we are now crossing, we need to clear the other path
            Path* otherPath = entry == 4 ? &outerPath : &innerPath;
            otherPath->target = -1;
        }
        
        // if the new path uncrosses, we reset the now unused side
        if (wasCrossed && !isCrossed) {
            if (entry == 4) {
                resetOuter();
            } else {
                resetInner();
            }
        }

        processDisplayAndSignals();
        upgradeTimer->start();
    } else {
        data.track = -1;
        data.entry = -1;
        upgradeTimer->stop();
    }

}

static void upgrade(Timer* timer) {
    timer->stop();
    if (data.entry == 0) {
        innerPath.direction = data.signalDirection;
    } else {
        outerPath.direction = data.signalDirection;
    }
    processDisplayAndSignals();
}