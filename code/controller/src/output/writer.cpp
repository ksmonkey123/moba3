#include <Arduino.h>
#include "writer.h"

#include "debugLog.h"
#include "switches.h"
#include "entrySignals.h"
#include "exitSignals.h"
#include "display.h"
#include "lights.h"

#include "../timer.h"
#include "../settings.h"
#include "../macros.h"

static void tick(Timer*);

void Writer::init() {
    Timer::create(NETWORK_TIMER_PERIOD, tick)->start();
}

// 20 chars in buffer are usable, the last char is reserved for a fixed NULL char to prevent buffer overflow.
static char buffer[21];
static byte index;

typedef void(*CommandProvider)(char*);

static CommandProvider commandProviders[] = {
    // normal commands
    DebugLog::getNextCommand,
    Switches::getNextCommand,
    EntrySignals::getNextCommand,
    ExitSignals::getNextCommand,
    Display::getNextCommand,
    Lights::getNextCommand,
    // continous retransmission
    #if RETRANSMIT
    Switches::getRepetitionCommand,
    EntrySignals::getRepetitionCommand,
    ExitSignals::getRepetitionCommand,
    Display::getRepetitionCommand,
    Lights::getRepetitionCommand,
    #endif
};

void fillBuffer() {
    for (byte i = 0; i < ARRAY_LENGTH(commandProviders); i++) {
        commandProviders[i](buffer);
        if (buffer[0] != '\0') {
            return;
        }
    }
}

static void tick(Timer*) {
    if (index == 0) {
        fillBuffer();
    }
    while(Serial.availableForWrite() > 0) {
        char c = buffer[index++];
        if (c == '\0') {
            index = 0;
            buffer[0] = '\0';
            return;
        }
        Serial.print(c);
    }
}
