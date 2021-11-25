#include <Arduino.h>
#include "network.h"

static CallbackFunction m_callback;

static char buffer[NETWORK_BUFFER_SIZE];
static byte buffer_length;

void idle(char c);
void hit(char c);
void listen(char c);
#define skip nullptr

static void (*state)(char) = idle;

void Network::init(CallbackFunction callback) {
    m_callback = callback;
    Serial.begin(NETWORK_BAUDRATE);
}

void Network::tick() {
    if (Serial.available()) {
        char c = Serial.read();
        if (c != 0) {
            if (c == '\n') {
                if (state == listen && m_callback != nullptr) {
                    m_callback(buffer, buffer_length);
                }
                buffer_length = 0;
                state = idle;
            } else if (state != nullptr) {
                state(c);
            }
        }
    }
}

void idle(char c) {
    state = (c == _chipConfig.type) ? hit : skip;
}

void hit(char c) {
    state = (c == _chipConfig.address || c == '+') ? listen : skip;
}

void listen(char c) {
    if (buffer_length >= NETWORK_BUFFER_SIZE) {
        state = skip;
    } else {
        buffer[buffer_length++] = c;
    }
}
