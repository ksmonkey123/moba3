#include "logic.h"
#include "signal.h"
#include "output.h"
#include "utils.h"
#include "settings.h"

void Signal::init() {
  Output::Config conf = {.idle = 0x4040, .inverted = true };
  Output::init(0x4040, &conf);

  memset(&_logicData.switches, 0, sizeof(Data));

  _logicData.signal.signal[0].state = 0x40;
  _logicData.signal.signal[1].state = 0x40;
  _logicData.signal.signal[0].pendingState = 0x40;
  _logicData.signal.signal[1].pendingState = 0x40;
}

void Signal::process(char* buffer, char length) {
  if ((length % 3) != 0 || length > 6) {
    return;
  }

  for (byte i = 0; i < length; i += 3) {
    Signal::Data::SignalState* signal = nullptr;
    if (buffer[i] == 'a') {
      signal = _logicData.signal.signal;
    } else if (buffer[i] == 'b') {
      signal = _logicData.signal.signal + 1;
    } else {
      return;
    }

    uint8_t pending = 0;

    switch (buffer[i + 2]) {
      case '0':
        pending = 0x0c;
        break;
      case '1':
        pending = 0x03;
        break;
      case '2':
        pending = 0x0a;
        break;
      case '3':
        pending = 0x0b;
        break;
      default:
        return;
    }

    switch (buffer[i + 1]) {
      case '0':
        pending = 0x40;
        break;
      case '1':
        pending |= 0x80;
        break;
      case '2':
        pending |= 0xa0;
        break;
      case '3':
        pending |= 0x90;
        break;
    }

    signal->pendingState = pending;
  }
  
}

void idle(Signal::Data::SignalState* signal, boolean highByte);
void core(Signal::Data::SignalState* signal, boolean highByte);
void secondary(Signal::Data::SignalState* signal, boolean highByte);
void tertiary(Signal::Data::SignalState* signal, boolean highByte);

inline void processSignal(Signal::Data::SignalState* signal, boolean highByte) {
  if (signal->step == nullptr) {
    signal->step = idle;
  }
  if (signal->shedule == 0 || signal->shedule < millis()) {
    signal->step(signal, highByte);
  }
}

void Signal::tick() {
  processSignal(_logicData.signal.signal + 0, false);
  processSignal(_logicData.signal.signal + 1, true);
}

void idle(Signal::Data::SignalState* signal, boolean highByte) {
  uint8_t pending = signal->pendingState;
  uint8_t state = signal->state;
  if (pending != state) {
    // need to start a cycle
    if ((pending & 0xf0) != (state & 0xf0)) {
      // full change
      Output::clearMask(0xff << (highByte ? 8 : 0));
    } else {
      // partial change (secondary only)
      Output::clearMask(0x0f << (highByte ? 8 : 0));
    }
    signal->state = pending;
    signal->step = core;
    signal->shedule = millis() + SIGNAL_BLANKING_INTERVAL;
  }
}

void core(Signal::Data::SignalState* signal, boolean highByte) {
  Output::setMask((signal->state & 0xcc) << (highByte ? 8 : 0));
  signal->step = secondary;
  signal->shedule = millis() + SIGNAL_PROPAGATION_DELAY;
}

void secondary(Signal::Data::SignalState* signal, boolean highByte) {
  Output::setMask((signal->state & 0xfe) << (highByte ? 8 : 0));
  signal->step = tertiary;
  signal->shedule = millis() + SIGNAL_PROPAGATION_DELAY;
}

void tertiary(Signal::Data::SignalState* signal, boolean highByte) {
  Output::setMask((signal->state & 0xff) << (highByte ? 8 : 0));
  signal->step = idle;
  signal->shedule = 0;
}

