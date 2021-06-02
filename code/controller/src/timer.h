#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer {
    public:
        Timer();
        static Timer* create(unsigned long, void(*handler)(Timer*));
        static void tickTimers();

        void setInterval(unsigned long);
        void setHandler(void(*handler)(Timer*));
        void configure(unsigned long, void(*handler)(Timer*));

        void start();
        void stop();
    private:
        void tick();

        boolean enabled;
        void (*handler)(Timer*);
        unsigned long interval;
        unsigned long lastTime;
};

#endif