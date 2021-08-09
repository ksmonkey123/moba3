#ifndef SETTINGS_H
#define SETTINGS_H

// #################
// # UART settings #
// #################
// - transmission speed
#define NETWORK_BAUDRATE 9600
// - the maximum number of characters that can be consumed between logic ticks. larger values may starve the logic classes of CPU cycles
#define NETWORK_MAX_ITERATIONS 10

#ifdef ARDUINO_AVR_UNO
#define LED_PIN LED_BUILTIN
#define DEBUG_LOG
#else
#define LED_PIN 2
#endif

#define TIMER_COUNT 5
#define SWITCH_DECODER_COUNT 5

#define DEFAULT_TIMER_PERIOD 10000
#define LED_PULSE_DURATION 50000
#define NETWORK_TIMER_PERIOD 100

#define DARKMODE_TIMEOUT 1000000

#endif
