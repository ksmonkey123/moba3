#ifndef SETTINGS_H
#define SETTINGS_H

// #################
// # UART settings #
// #################
// - transmission speed
#define NETWORK_BAUDRATE 2000000
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

// ############################
// # CONFIGURATION DIP-SWITCH #
// ############################

// - a 6-channel DIP-switch is used. 3 channels define the decoder type, while the other 3 define the address
#define CONFIG_PIN_ADDR_1 A0
#define CONFIG_PIN_ADDR_2 A1
#define CONFIG_PIN_ADDR_4 A2
#define CONFIG_PIN_TYPE_1 A3
#define CONFIG_PIN_TYPE_2 A4
#define CONFIG_PIN_C_FLAG A5

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
