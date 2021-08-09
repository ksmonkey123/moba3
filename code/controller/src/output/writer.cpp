#include <Arduino.h>
#include "writer.h"

#include "switches.h"
#include "display.h"

#include "../timer.h"
#include "../settings.h"

static void tick(Timer* timer);

void Writer::init() {
    Timer::create(NETWORK_TIMER_PERIOD, tick)->start();
}

static char buffer[20];
static byte index;

void fillBuffer() {
    Switches::getNextCommand(buffer);
    if (buffer[0] == '\0') {
        Display::getNextCommand(buffer);
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
