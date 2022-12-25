#include <Arduino.h>
#include "debugLog.h"

#define BUFFER_SIZE 200

static char _buffer[BUFFER_SIZE];
static uint8_t buffer_size;
static uint8_t ring_offset;

bool DebugLog::enabled;

void DebugLog::append(char* buffer, uint8_t length) {
  // only accept if enough space in buffer
  if (buffer_size + length > BUFFER_SIZE) {
    return;
  }
  
  for (uint8_t i = 0; i < length; i++) {
    _buffer[(ring_offset + buffer_size + i) % BUFFER_SIZE] = buffer[i];
  }
  buffer_size += length;
}

void DebugLog::getNextCommand(char* buffer) {
  // nothing to send
  if (buffer_size == 0) {
    buffer[0] = '\0';
    return;
  }

  // send in packets of 20 chars
  uint8_t tx_size = buffer_size > 20 ? 20 : buffer_size;

  for (uint8_t i = 0; i < tx_size; i++) {
    buffer[i] = _buffer[(ring_offset + i) % BUFFER_SIZE];
  }
  buffer[tx_size] = '\0';
  ring_offset = (ring_offset + tx_size) % BUFFER_SIZE;
  buffer_size -= tx_size;
}
