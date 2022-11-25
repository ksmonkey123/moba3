#include "async.h"
#include "settings.h"

static struct Async {
    uint32_t expirationTime;
    void(*callback)();
} _asyncs[ASYNC_COUNT];

boolean async(void(*callback)(), uint32_t timeout) {
    for (byte i = 0; i < ASYNC_COUNT; i++) {
        Async* async = _asyncs + i;
        if (async->callback == nullptr) {
            async->callback = callback;
            async->expirationTime = timeout + millis();
            return true;
        }
    }
    #ifdef DEBUG_LOG
    Serial.println("# no free async slot");
    #endif
    return false;
}

void async_abort(void(*callback)()) {
    for (byte i = 0; i < ASYNC_COUNT; i++) {
        if (_asyncs[i].callback == callback) {
            _asyncs[i].callback = nullptr;
        }
    }
}

void async_unique(void(*callback)(), uint32_t timeout) {
    async_abort(callback);
    async(callback, timeout);
}

void async_tick() {
    static uint32_t lastCheck = 0;

    uint32_t time = millis();

    if (time == lastCheck) {
        return;
    }

    lastCheck = time;

    for (byte i = 0; i < ASYNC_COUNT; i++) {
        Async* async = _asyncs + i;

        if (async->callback != nullptr) {
            if (async->expirationTime < time) {
                void(*func)() = async->callback;
                async->callback = nullptr;
                func();
            }
        }
    }
}
