#ifndef CONTROL_RAILROAD_STATION_H
#define CONTROL_RAILROAD_STATION_H

#include "../../../settings.h"

/* data & functionality common to both station sides */
enum SignalDirection { DISABLED, ENTRY, EXIT };

enum SignalState { FB_0, FB_1, FB_2, FB_3 };

extern SignalLevel exitSignalsLeft[];
extern SignalLevel exitSignalsRight[];

namespace Station::Left {
    void refreshSignals();
}
namespace Station::Right {
    void refreshSignals();
}

#endif
