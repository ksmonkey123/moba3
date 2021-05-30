#ifndef CONFIG_H
#define CONFIG_H

namespace Config {
    enum Type {
        NONE = 0,
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
    void load();
}

extern Config::Configuration _chipConfig;

#endif
