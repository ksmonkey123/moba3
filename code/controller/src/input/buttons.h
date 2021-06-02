#ifndef INPUT_BUTTONS_H
#define INPUT_BUTTONS_H

#include <Arduino.h>

/**
 * model holding the current button state as provided by the I/O board
 */
namespace Buttons {

    void init();

    /**
     * processes a single button event as provided by the I/O board
     * 
     * @param buffer the input buffer holding a (non-terminated) 3 characters long string.
     * Format: `[A-D][0-9a-f][+-]`
     *  - channel selection [A-D = 0-3]
     *  - button address
     *  - direction [+ = down, - = up]
     */
    void processInput(char* buffer);

    /**
     * read the state of a single butto
     * 
     * @param id the encoded button id. The high nibble holds the sector id (0-3), the low nibble holds the button id (0-f).
     * @return the button state
     */
    boolean read(byte id);

    /**
     * reads the state of all buttons in the list
     * 
     * @param buttons the button ids to check. each id will be replaced by 0 or 1 to represent the button state.
     * @param len the length of the buttons array
     * @param firstIndex pinter where the index of the first pressed button is written. passing a nullptr disables this.
     * @param lastIndex pointer where the index of the last pressed button is written. passing a nullptr disables this.
     * @return the number of pressed buttons
     */
    byte readList(byte* buttons, byte len, byte* firstIndex, byte* lastIndex);

}

#endif
