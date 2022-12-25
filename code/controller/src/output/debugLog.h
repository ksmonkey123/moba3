#ifndef OUTPUT_DEBUG_LOG_H
#define OUTPUT_DEBUG_LOG_H

namespace DebugLog {
    void append(char* buffer, uint8_t length);
    void getNextCommand(char* buffer);
    extern bool enabled;
}

#endif
