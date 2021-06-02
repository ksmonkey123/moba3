#ifndef CONTROL_MODULES_H
#define CONTROL_MODULES_H

#include <Arduino.h>

#include "../input/buttons.h"
#include "../input/buttonMapping.h"
#include "../output/switches.h"
#include "../output/display.h"
#include "../output/switchMapping.h"
#include "../timer.h"

/** initialises all processing modules */
void initControllers();

/** manages the track switches */
namespace Tracks { void init(); };
namespace Yard   { void init(); };

#endif