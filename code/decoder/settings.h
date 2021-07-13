#ifndef SETTINGS_H
#define SETTINGS_H

// #################
// # UART settings #
// #################
// - transmission speed
#define NETWORK_BAUDRATE 9600
// - the network buffer size defines the max. supported command length (not including addressing and termination character)
#define NETWORK_BUFFER_SIZE 12
// - the maximum number of characters that can be consumed between logic ticks. larger values may starve the logic classes of CPU cycles
#define NETWORK_MAX_ITERATIONS 10

// ################
// # SPI settings #
// ################
#define OUTPUT_SPI_SETTINGS SPISettings(20000000, MSBFIRST, SPI_MODE0)
#define OUTPUT_LATCH_PIN 10
#define OUTPUT_ENABLE_PIN 9

#define LED_PIN 2

// ####################
// # CONTROL SETTINGS #
// ####################

// - the pulse length for a short switching impulse. (ms)
#define SWITCH_DRIVE_TIME_LOW 1000
// - the pulse length for a long switching impulse. (ms)
#define SWITCH_DRIVE_TIME_HIGH 2000
// - the blanking time while switching signals. (ms)
#define SIGNAL_BLANKING_INTERVAL 400
// - the turn-on delay between individual lamps on a switching signal. (ms)
#define SIGNAL_PROPAGATION_DELAY 40


#endif
