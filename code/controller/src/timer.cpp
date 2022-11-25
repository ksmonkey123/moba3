#include "timer.h"
#include "settings.h"

static byte timerCount;
static Timer timers[TIMER_COUNT];

#ifdef DEBUG_LOG
static void logTimerCreation() {
    Serial.print(F("# T "));
    Serial.print(timerCount);
    Serial.print('/');
    Serial.println(TIMER_COUNT);
}
#endif

static void freezeTooManyTimers() {
    while (true) {
        digitalWrite(LED_PIN, true);
        #ifdef DEBUG_LOG
        logTimerCreation();
        #endif
        delay(1000);
    }
}

Timer* Timer::create(unsigned long interval, void (*handler)(Timer*)) {
    auto index = timerCount++;
    if (index >= TIMER_COUNT) {
        freezeTooManyTimers();
    }
    #ifdef DEBUG_LOG
    logTimerCreation();
    #endif
    timers[index] = Timer();
    timers[index].configure(interval, handler);
    return timers + index;
}

Timer* Timer::create(void (*handler)(Timer*)) {
    return create(DEFAULT_TIMER_PERIOD, handler);
}

Timer::Timer() {
    this->configure(0, nullptr);
}

void Timer::configure(unsigned long interval, void (*handler)(Timer*)) {
    this->interval = interval;
    this->handler = handler;
}

void Timer::setInterval(unsigned long interval) {
    this->interval = interval;
}

void Timer::setHandler(void (*handler)(Timer*)) {
    this->handler = handler;
}

void Timer::start() {
    this->lastTime = micros();
    this->enabled = true;
}

void Timer::stop() {
    this->enabled = false;
}

void Timer::tickTimers() {
    for (byte i = 0; i < timerCount; i++) {
        if (timers[i].enabled) {
            timers[i].tick();
        }
    }
}

void Timer::tick() {
    auto currentMicros = micros();
    if (currentMicros - this->lastTime > this->interval) {
        this->lastTime = currentMicros;
        this->handler(this);
    }
}
