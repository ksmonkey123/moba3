#ifndef SETTINGS_H
#define SETTINGS_H

// #################
// # UART settings #
// #################
// - transmission speed
#define NETWORK_BAUDRATE 9600
// - the maximum number of characters that can be consumed between logic ticks. larger values may starve the logic classes of CPU cycles
#define NETWORK_MAX_ITERATIONS 10

#define LED_PIN 2
#define TIMER_COUNT 10
#define SWITCH_DECODER_COUNT 5

#endif
