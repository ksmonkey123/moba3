#ifndef CONTROL_MODULES_H
#define CONTROL_MODULES_H

#include <Arduino.h>

#include "../input/buttons.h"
#include "../input/buttonMapping.h"
#include "../output/switches.h"
#include "../output/entrySignals.h"
#include "../output/display.h"
#include "../output/switchMapping.h"
#include "../output/entrySignalMapping.h"
#include "../output/exitSignals.h"
#include "../output/exitSignalMapping.h"
#include "../timer.h"
#include "../settings.h"

/** initialises all processing modules */
void initControllers();

/** blink LED */
void blinkLED();

/** manages the track switches */
namespace Yard      { void init(); }
namespace Tracks    { void init(); }
namespace Station {
    namespace Left  { void init(); }
    namespace Right { void init(); }
}

/** lighting controllers */

/** system-wide controllers */
namespace Darkmode  { void init(); }
namespace ForcedUpd { void init(); }

#endif
