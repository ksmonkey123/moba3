#ifndef SETTINGS_H
#define SETTINGS_H

// #################
// # UART settings #
// #################
// - transmission speed
#define NETWORK_BAUDRATE 250000
// - the maximum number of characters that can be consumed between logic ticks. larger values may starve the logic classes of CPU cycles
#define NETWORK_MAX_ITERATIONS 10

#ifdef ARDUINO_AVR_UNO
    #define LED_PIN LED_BUILTIN
    #define DEBUG_LOG
    #define PROXY_AVAIL
    // using the controller shield (rev. A) for arduino UNO, we must actively pull pin 2 high to enable the signal busses.
    // by default all pins are INPUT on reset and an external pull-down resistor pulls pin 2 low. This disables all serial bus transmissions
    // while the controller software is not running. This allows for in-circuit programming of the Arduino Uno over USB. The inbound
    // lane of the local bus (Rx) has priority and masks any data coming in via USB. Pulling disabling the serial busses allows the
    // USB interface to communicate with the Arduino (and its bootloader) until the controller software starts running. 
    #define RS485_ENABLE 2
#else
    #define LED_PIN 2
#endif

#define RETRANSMIT true

#define TIMER_COUNT 2
#define ASYNC_COUNT 16

#define LIGHT_DECODER_COUNT 4
#define SWITCH_DECODER_COUNT 5
#define EXIT_SIGNAL_DECODER_COUNT 2
#define ENTRY_SIGNAL_DECODER_COUNT 2

#define DEFAULT_TIMER_PERIOD         10000 // [us]
#define LED_PULSE_DURATION          100    // [ms]
#define NETWORK_TIMER_PERIOD           100 // [us]
#define DARKMODE_TIMEOUT           1000000 // [us]
#define SWITCH_STAGGERING_PERIOD    100    // [ms]
#define SIGNAL_UPGRADE_DELAY        500    // [ms]
#define COMMAND_REPETITION_PERIOD  1000    // [ms]
#define LIGHT_STAGGERING_PERIOD      10    // [ms]

#endif
