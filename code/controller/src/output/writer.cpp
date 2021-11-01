#include <Arduino.h>
#include "writer.h"

#include "switches.h"
#include "entrySignals.h"
#include "exitSignals.h"
#include "display.h"
#include "lights.h"

#include "../timer.h"
#include "../settings.h"
#include "../macros.h"

static void tick(Timer* timer);

void Writer::init() {
    Timer::create(NETWORK_TIMER_PERIOD, tick)->start();
}

static char buffer[20];
static byte index;

typedef void(*CommandProvider)(char*);

static CommandProvider commandProviders[] = {
    // normal commands
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

static void tick(Timer* timer) {
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
