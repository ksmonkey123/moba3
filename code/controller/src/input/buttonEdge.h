#ifndef INPUT_BUTTON_EDGE_H
#define INPUT_BUTTON_EDGE_H

#include <Arduino.h>

class ButtonEdge {
    public:
        ButtonEdge(byte buttonId);
        boolean test();
    private:
        byte buttonId;
        boolean triggered;
};

#endif