#ifndef ASYNC_H
#define ASYNC_H

#include <Arduino.h>

boolean async(void(*callback)(), uint32_t timeout);

void async_abort(void(*callback)());

void async_tick();

#endif
