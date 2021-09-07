#include "../../control_modules.h"
#include "station.h"

static void tick(Timer*);
static void upgrade(Timer*);

EntrySignals::STATUS exitSignalsLeft[4];

static Timer* upgradeTimer;

struct Path {
    int8_t target;
    SignalDirection direction;
};

static Path paths[] = {
    { .target = -1, .direction = SignalDirection::DISABLED },
    { .target = -1, .direction = SignalDirection::DISABLED },
    { .target = -1, .direction = SignalDirection::DISABLED }};

void Station::Left::init() {
    Timer::create(tick)->start();
    upgradeTimer = Timer::create(SIGNAL_UPGRADE_DELAY, upgrade);
}

static void doReset() {
    paths[0].target = -1;
    paths[1].target = -1;
    paths[2].target = -1;
    Switches::setSwitch(SWITCH_LEFT_1, Switches::UNKNOWN);
    Switches::setSwitch(SWITCH_LEFT_2, Switches::UNKNOWN);
    Switches::setSwitch(SWITCH_LEFT_3, Switches::UNKNOWN);
    Switches::setSwitch(SWITCH_LEFT_4, Switches::UNKNOWN);
    Switches::setSwitch(SWITCH_LEFT_5, Switches::UNKNOWN);
    Display::set(3, 0x00, 0xff);
    Display::set(5, 0x00, 0x0f);
}

static void processSwitches(byte entry, byte track) {
    switch(entry * 16 + track) {
        // main paths
        case 0x00: {
            Switches::setSwitch(SWITCH_LEFT_1, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_LEFT_2, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_LEFT_3, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_LEFT_4, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_LEFT_5, Switches::DIVERGING);
            break;
        }
        case 0x01: {
            Switches::setSwitch(SWITCH_LEFT_1, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_LEFT_2, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_LEFT_3, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_LEFT_4, Switches::DIVERGING);
            break;
        }
        case 0x02: {
            Switches::setSwitch(SWITCH_LEFT_1, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_LEFT_2, Switches::STRAIGHT);
            break;
        }
        case 0x03: {
            Switches::setSwitch(SWITCH_LEFT_1, Switches::STRAIGHT);
            break;
        }
        // shunting track 1
        case 0x10: {
            Switches::setSwitch(SWITCH_LEFT_5, Switches::STRAIGHT);
            break;
        }
        // shunting track 2
        case 0x20: {
            Switches::setSwitch(SWITCH_LEFT_3, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_LEFT_4, Switches::STRAIGHT);
            Switches::setSwitch(SWITCH_LEFT_5, Switches::DIVERGING);
            break;
        }
        case 0x21: {
            Switches::setSwitch(SWITCH_LEFT_3, Switches::DIVERGING);
            Switches::setSwitch(SWITCH_LEFT_4, Switches::DIVERGING);
            break;
        }
        // all others are invalid
        default: {
            return;
        }
    }
}

static void processDisplay() {
    byte sector_3 = 0x00;
    byte sector_5 = 0x00;

    // process main path
    if (paths[0].target >= 0) {
        byte segment = paths[0].direction == DISABLED ? 0x03 : paths[0].direction == ENTRY ? 0x01 : 0x02;
        sector_3 |= segment << (paths[0].target * 2);
        if (segment != 0x03) {
            segment ^= 0x03;
        }
        sector_5 |= segment;
    }
    
    // process sh_1 path
    if (paths[1].target >= 0) {;
        sector_3 |= 0x03 << (paths[1].target * 2);
        sector_5 |= 0x08;
    }
    
    // process sh_2 path
    if (paths[2].target >= 0) {;
        sector_3 |= 0x03 << (paths[2].target * 2);
        sector_5 |= 0x04;
    }

    // publish
    Display::set(3, sector_3, 0xff);
    Display::set(5, sector_5, 0x0f);

}

static void processSignals() {
    Station::Left::refreshSignals();

    // build exit signals
    auto target = paths[0].target;
    auto direction = paths[0].direction;
    memset(exitSignalsLeft, 0, sizeof(exitSignalsLeft));

    byte data = 0;
    if (target >= 0 && direction == EXIT) {
        switch(target) {
            case 0:
            case 1:
                exitSignalsLeft[target] = EntrySignals::SLOW_40;
                break;
            case 2:
                exitSignalsLeft[target] = EntrySignals::SLOW_60;
                break;
            case 3:
                exitSignalsLeft[target] = EntrySignals::FREE;
                break;
        }
        data = 0x01 << target;
    }

    ExitSignals::setSignal(EXIT_SIGNALS_L, data, 0x1f);
    Station::Right::refreshSignals();
}

void Station::Left::refreshSignals() {
    auto target = paths[0].target;
    auto direction = paths[0].direction;

    if (target >= 0 && direction == ENTRY) {
        EntrySignals::STATUS speed = EntrySignals::SLOW_40;

        if (target == 2) {
            speed = EntrySignals::SLOW_60;
        } else if (target == 3) {
            speed = exitSignalsRight[3] != EntrySignals::HALT ? EntrySignals::FREE : EntrySignals::SLOW_60;
        }

        EntrySignals::setSignal(ENTRY_SIGNAL_LEFT, speed, exitSignalsRight[target]);
    } else {
        EntrySignals::setSignal(ENTRY_SIGNAL_LEFT, EntrySignals::HALT, EntrySignals::HALT);
    }
}

static void processDisplayAndSignals() {
    processDisplay();
    processSignals();
}

static struct {
    SignalDirection signalDirection;
    byte track;
    byte entry;
} data;

static void buildPath(byte track, byte entry) {  
    // active path can always be set
    paths[entry].target = track;
    paths[entry].direction = DISABLED;

    // check for potential collisions and clear offending paths
    if (entry == 0) {
        switch(track) {
            case 0:
                paths[1].target = -1;
            case 1:
                paths[2].target = -1;
        }
    } else if (entry == 1) {
        if (paths[0].target == 0) {
            paths[0].target = -1;
        }
        if (paths[2].target == 0) {
            paths[2].target = -1;
        }
    } else if (entry == 2) {
        if (paths[0].target < 2) {
            paths[0].target = -1;
        }
        if (track == 0 && paths[1].target == 0) {
            paths[1].target = -1;
        }
    }
}

static void tick(Timer*) {
    if (Buttons::read(BUTTON_STATION_CLEAR_L)) {
        doReset();
        data.signalDirection = DISABLED;
        upgradeTimer->stop();
        return;
    }

    byte buttons[] = {
        BUTTON_STATION_TRACK_1,
        BUTTON_STATION_TRACK_2,
        BUTTON_STATION_TRACK_3,
        BUTTON_STATION_TRACK_4,
        BUTTON_STATION_ENTRY_L,
        BUTTON_STATION_SHUNT_1,
        BUTTON_STATION_SHUNT_2
    };

    byte track, entry;
    byte pressedCount = Buttons::readList(buttons, 7, &track, &entry);

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

        buildPath(track, entry - 4);

        processSwitches(entry - 4, track);
        processDisplayAndSignals();
        if (entry == 4) {
            upgradeTimer->start();
        }
    } else {
        data.track = -1;
        data.entry = -1;
        upgradeTimer->stop();
    }
}

static void upgrade(Timer* timer) {
    timer->stop();
    if (data.entry != 0) {
        // path leads to shunting track - no signals to update
        return;
    }
    paths[0].direction = data.signalDirection;
    processDisplayAndSignals();
}