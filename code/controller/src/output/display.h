#ifndef OUTPUT_DECODER_LEDS_H
#define OUTPUT_DECODER_LEDS_H

#include <Arduino.h>

/**
 * Management of the Display LEDs on the control board.
 */
namespace Display {
    
    /**
     * updates a single byte of the display.
     * 
     * @param sector the id of the display sector (0..5)
     * @param data the data to set
     * @param mask the mask to apply to the data (only bits set in the mask are updated)
     */
    void set(byte sector, byte data, byte mask);

    void getNextCommand(char* buffer);

    void toggleDarkmode();
}

#endif