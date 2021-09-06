#include "control_modules.h"

void initControllers() {
    #ifdef DEBUG_LOG
    Serial.println();
    Serial.println("-------------------");
    Serial.println("loading controllers");
    Serial.println("-------------------");
    #endif
    
    Yard::init();
    Tracks::init();
    Station::Left::init();
    Station::Right::init();

    Darkmode::init();
}
