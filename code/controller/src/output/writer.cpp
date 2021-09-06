#include <Arduino.h>
#include "writer.h"

#include "switches.h"
#include "entrySignals.h"
#include "exitSignals.h"
#include "display.h"

#include "../timer.h"
#include "../settings.h"

static void tick(Timer* timer);

void Writer::init() {
    #ifdef DEBUG_LOG
    Serial.println("init writer");
    #endif
    Timer::create(NETWORK_TIMER_PERIOD, tick)->start();
}

static char buffer[20];
static byte index;

static void(*commandProviders[])(char*) = {
    Switches::getNextCommand,
    EntrySignals::getNextCommand,
    ExitSignals::getNextCommand,
    Display::getNextCommand,
};

void fillBuffer() {
    byte size = sizeof(commandProviders) / sizeof(commandProviders[0]);
    for (byte i = 0; i < size; i++) {
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
