#include "buttonEdge.h"
#include "buttons.h"

ButtonEdge::ButtonEdge(byte buttonId) {
    this->buttonId = buttonId;
}

boolean ButtonEdge::test() {
    if (this->triggered != Buttons::read(this->buttonId)) {
        this->triggered = !this->triggered;
        return this->triggered;
    }
    return false;
}
