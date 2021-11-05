#ifndef CONTROL_MODULES_H
#define CONTROL_MODULES_H

#include <Arduino.h>

#include "../input/buttons.h"
#include "../input/buttonEdge.h"
#include "../input/buttonMapping.h"

#include "../output/signalLevel.h"
#include "../output/switches.h"
#include "../output/entrySignals.h"
#include "../output/display.h"
#include "../output/switchMapping.h"
#include "../output/entrySignalMapping.h"
#include "../output/exitSignals.h"
#include "../output/exitSignalMapping.h"
#include "../output/lights.h"

#include "../timer.h"
#include "../async.h"
#include "../settings.h"

/** initialises all processing modules */
void initControllers();

/** blink LED */
void blinkLED();

/** manages the track switches */
namespace Yard      { void tick(); }
namespace Tracks    { void tick(); }
namespace Station {
    namespace Left  { void tick(); }
    namespace Right { void tick(); }
}

/** lighting controllers */
namespace Light     { void tick(); }

/** system-wide controllers */
namespace Darkmode  { void tick(); }
namespace ForcedUpd { void tick(); }

#endif
