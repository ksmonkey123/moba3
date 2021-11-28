#include <Arduino.h>
#include <SPI.h>

#include "network.h"
#include "logic.h"
#include "config.h"

void setup() {
  _chipConfig.type = Config::Type::SWITCH;
  _chipConfig.address = '4';

  Logic::init();
  Network::init(_logicConfig.process);
}

void loop() {
  Network::tick();
  if (_logicConfig.tick != nullptr) {
    _logicConfig.tick();
  }
}
