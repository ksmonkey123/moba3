#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer {
    public:
        Timer(unsigned long interval, void(*callback)());
        void setInterval(unsigned long interval);
        void tick();
    private:
        void (*callback)();
        unsigned long interval;
        unsigned long nextExpiration;
};

#endif