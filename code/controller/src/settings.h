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

#define RETRANSMIT true

#define TIMER_COUNT 3
#define ASYNC_COUNT 16

#define LIGHT_DECODER_COUNT 4
#define SWITCH_DECODER_COUNT 5
#define EXIT_SIGNAL_DECODER_COUNT 2
#define ENTRY_SIGNAL_DECODER_COUNT 2

#define DEFAULT_TIMER_PERIOD         10000 // [us]
#define LED_PULSE_DURATION          100000 // [us]
#define NETWORK_TIMER_PERIOD           100 // [us]
#define DARKMODE_TIMEOUT           1000000 // [us]
#define SWITCH_STAGGERING_PERIOD    100    // [ms]
#define SIGNAL_UPGRADE_DELAY       1000    // [ms]
#define COMMAND_REPETITION_PERIOD  1000    // [ms]
#define LIGHT_STAGGERING_PERIOD      10    // [ms]

#endif
