#ifndef LOGIC_H
#define LOGIC_H

#include "output.h"
#include "config.h"

#include "switches.h"
#include "signal.h"
#include "exit_signal.h"

namespace Logic {
    struct Config {
        void (*init)();
        void (*process)(char*,char);
        void (*tick)();
    };

    union Data {
        Switches::Data switches;
        Signal::Data signal;
        ExitSignal::Data exitSignal;
    };
    
    void init();
}

extern Logic::Config _logicConfig;
extern Logic::Data   _logicData;

#endif