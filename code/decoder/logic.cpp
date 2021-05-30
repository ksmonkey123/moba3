#include "logic.h"
#include "light.h"

Logic::Config _logicConfig;
Logic::Data _logicData;

void Logic::init() {
    memset(&_logicConfig, 0, sizeof(Logic::Config));

    switch(_chipConfig.type) {
        case ::Config::Type::LIGHT:
        case ::Config::Type::EXIT:
            _logicConfig.init = Light::init;
            _logicConfig.process = Light::process;
            break;
        case ::Config::Type::SWITCH:
            _logicConfig.init = Switches::init;
            _logicConfig.process = Switches::process;
            _logicConfig.tick = Switches::tick;
            break;
        case ::Config::Type::ENTRY:
            _logicConfig.init = Signal::init;
            _logicConfig.process = Signal::process;
            _logicConfig.tick = Signal::tick;
    }

    if (_logicConfig.init != nullptr) {
        _logicConfig.init();
    }
}
