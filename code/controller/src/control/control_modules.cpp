#include "control_modules.h"
#include "../timer.h"

static void process(Timer* timer) {
    Yard::tick();
    Tracks::tick();
    Station::Left::tick();
    Station::Right::tick();
    Darkmode::tick();
    ForcedUpd::tick();
    Light::tick();
}

void initControllers() {
    Timer::create(process)->start();
}
