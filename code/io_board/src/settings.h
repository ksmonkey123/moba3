#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>

// #################
// # UART settings #
// #################
// - transmission speed
#define NETWORK_BAUDRATE 250000
// - the network buffer size defines the max. supported command length (not including addressing and termination character)
#define NETWORK_BUFFER_SIZE 12
// - the maximum number of characters that can be consumed between logic ticks. larger values may starve the logic classes of CPU cycles
#define NETWORK_MAX_ITERATIONS 10

#define NO_UPDATE_TIMEOUT 2000
#define UPDATE_TICK_PULSE   20

// ################
// # SPI settings #
// ################
#define OUTPUT_SPI_SETTINGS SPISettings(1000000, MSBFIRST, SPI_MODE0)
#define OUTPUT_LATCH_PIN 10
#define OUTPUT_ENABLE_PIN 9
#define INPUT_LATCH_PIN 8

#define INPUT_CHANNELS {A0,A1,A2,A3}

#define LED_PIN 2

#endif
