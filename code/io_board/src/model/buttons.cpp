#include "buttons.h"
#include "../networking/eventHandler.h"
#include "../statusLed.h"

static uint16_t states[4][3];
static uint16_t last_composites[4];
static byte sample_count;

void Buttons::update(uint16_t* buffer) {
    for (byte i = 0; i < 4; i++) {
      // record samples
      states[i][sample_count] = buffer[i];
    }

    sample_count++;

    if (sample_count == 3) {
      // process samples
      for (byte i = 0; i < 4; i++) {
        uint16_t AB = (states[i][0] & states[i][1]);
        uint16_t AC = (states[i][0] & states[i][2]);
        uint16_t BC = (states[i][1] & states[i][2]);

        // composite: majority rule: bit is 1 if at least 2 samples are 1.
        uint16_t composite_sample = AB | AC | BC;

        // mask shows differences between last composite and this one
        uint16_t mask = last_composites[i] ^ composite_sample;

        // save composite
        last_composites[i] = composite_sample;

        // if any difference present: process
        if (mask != 0) {
          StatusLED::blink();
          EventHandler::handle(i, composite_sample, mask);
        }
      }

      // reset sample count
      sample_count = 0;
    }
}