#include <Arduino.h>
#include "writer.h"

#include "switches.h"
#include "../timer.h"

void Writer::init() {
}

static char buffer[20];
static byte index;

void fillBuffer() {
    Switches::getNextCommand(buffer);
}

static Timer timer = Timer(100, fillBuffer);

void Writer::tick() {
    if (index == 0) {
        timer.tick();
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