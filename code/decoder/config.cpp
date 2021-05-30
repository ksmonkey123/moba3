#include <Arduino.h>

#include "settings.h"
#include "config.h"

Config::Configuration _chipConfig;

Config::Type readType() {
    pinMode(CONFIG_PIN_TYPE_1, INPUT_PULLUP);
    pinMode(CONFIG_PIN_TYPE_2, INPUT_PULLUP);
    
    uint8_t value = 0;

    value += digitalRead(CONFIG_PIN_TYPE_1) ? 0 : 1;
    value += digitalRead(CONFIG_PIN_TYPE_2) ? 0 : 2;
    
    switch (value) {
        case 0:
            return Config::Type::LIGHT;
        case 1:
            return Config::Type::SWITCH;
        case 2:
            return Config::Type::ENTRY;
        case 3:
            return Config::Type::EXIT;
        default:
            return Config::Type::NONE;
    }
}

char readAddress() {
    pinMode(CONFIG_PIN_ADDR_1, INPUT_PULLUP);
    pinMode(CONFIG_PIN_ADDR_2, INPUT_PULLUP);
    pinMode(CONFIG_PIN_ADDR_4, INPUT_PULLUP);
    
    uint8_t value = 0;

    value += digitalRead(CONFIG_PIN_ADDR_1) ? 0 : 1;
    value += digitalRead(CONFIG_PIN_ADDR_2) ? 0 : 2;
    value += digitalRead(CONFIG_PIN_ADDR_4) ? 0 : 4;

    if (value > 0 && value <= 8) {
        return '0' + value;
    } else {
        return 0;
    }
}

boolean readCustomFlag() {
    pinMode(CONFIG_PIN_C_FLAG, INPUT_PULLUP);
    return !digitalRead(CONFIG_PIN_C_FLAG);
}


void Config::load() {
    _chipConfig.type = readType();
    _chipConfig.address = readAddress();
    _chipConfig.customFlag = readCustomFlag();

    if (_chipConfig.type == Type::NONE || _chipConfig.address == 0) {
        _chipConfig.type = Type::NONE;
        _chipConfig.address = 0;
        _chipConfig.customFlag = false;
    }
}
