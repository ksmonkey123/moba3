#include <Arduino.h>

namespace Buttons {

    struct ButtonSector {
        boolean button[16];
    };

    struct ButtonModel {
        ButtonSector sector[5];
    };

    void init();
    void processInput(char*);

}

extern Buttons::ButtonModel _buttons;
