#include "control_modules.h"

void initControllers() {
    Yard::init();
    Tracks::init();
    Station::Left::init();
    Station::Right::init();
    Darkmode::init();
    ForcedUpd::init();
}
