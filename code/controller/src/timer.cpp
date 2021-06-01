#include "timer.h"

Timer::Timer(unsigned long interval, void(*callback)()) {
    this->interval = interval;
    this->callback = callback;
}

void Timer::setInterval(unsigned long interval) {
    this->interval = interval;
}

void Timer::tick() {
    auto time = micros();
    if (this->nextExpiration < time) {
        this->nextExpiration = time + this->interval;
        this->callback();
    }
}
