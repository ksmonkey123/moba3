#include <Arduino.h>
#include "writer.h"

#include "switches.h"
#include "display.h"

#include "../timer.h"

void tick(Timer* timer);

void Writer::init() {
    Timer::create(100, tick)->start();
}

static char buffer[20];
static byte index;

void fillBuffer() {
    Switches::getNextCommand(buffer);
    if (buffer[0] == 0) {
        Display::getNextCommand(buffer);
    }
}

void tick(Timer* timer) {
    if (index == 0) {
        fillBuffer();
    }
    while(Serial.availableForWrite() > 0) {
        char c = buffer[index++];
        if (c == 0) {
            index = 0;
            buffer[0] = 0;
            return;
        }
        Serial.print(c);
    }
}
