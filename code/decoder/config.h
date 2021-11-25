#ifndef CONFIG_H
#define CONFIG_H

namespace Config {
    enum Type {
        SWITCH = 'W',
        LIGHT = 'L',
        ENTRY = 'E',
        EXIT = 'A'
    };

    struct Configuration {
        Type type;
        char address;
        boolean customFlag;
    };
}

extern Config::Configuration _chipConfig;

#endif
