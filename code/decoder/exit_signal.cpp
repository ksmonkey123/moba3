#include "logic.h"
#include "exit_signal.h"
#include "output.h"
#include "utils.h"
#include "settings.h"

void ExitSignal::init() {
  Output::Config conf = {.idle = 0x4444, .inverted = true };
  Output::init(0x4444, &conf);

  memset(&_logicData.switches, 0, sizeof(Data));

  for (byte i = 0; i < 4; i++) {
    auto signal = _logicData.exitSignal.signal + i;
    signal->state = 0x04;
    signal->pendingState = 0x04;
  }
}

void ExitSignal::process(char* buffer, char length) {
  if ((length % 2) != 0 || length > 8) {
    return;
  }

  for (byte i = 0; i < length; i += 2) {
    ExitSignal::Data::SignalState* signal = nullptr;
    char selector = buffer[i];

    if (selector >= 'a' && selector <= 'd') {
      signal = _logicData.exitSignal.signal + (selector - 'a');
    } else {
      return;
    }

    uint8_t pending = 0;

    switch (buffer[i + 1]) {
      case '0':
        pending = 0x04;
        break;
      case '1':
        pending = 0x08;
        break;
      case '2':
        pending = 0x0a;
        break;
      case '3':
        pending = 0x09;
        break;
    }

    signal->pendingState = pending;
  }
  
}

void idle(ExitSignal::Data::SignalState* signal, byte channel);
void core(ExitSignal::Data::SignalState* signal, byte channel);
void secondary(ExitSignal::Data::SignalState* signal, byte channel);

inline void processSignal(ExitSignal::Data::SignalState* signal, byte channel) {
  if (signal->step == nullptr) {
    signal->step = idle;
  }
  if (signal->schedule == 0 || signal->schedule < millis()) {
    signal->step(signal, channel);
  }
}

void ExitSignal::tick() {
  for (byte i = 0; i < 4; i++) {
    processSignal(_logicData.exitSignal.signal + i, i);
  }
}

void idle(ExitSignal::Data::SignalState* signal, byte channel) {
  uint8_t pending = signal->pendingState;
  uint8_t state = signal->state;
  if (pending != state) {
    // need to start a cycle
    Output::clearMask(0x0f << (channel * 4));
    
    signal->state = pending;
    signal->step = core;
    signal->schedule = millis() + SIGNAL_BLANKING_INTERVAL;
  }
}

void core(ExitSignal::Data::SignalState* signal, byte channel) {
  Output::setMask((signal->state & 0x0c) << (channel * 4));
  signal->step = secondary;
  signal->schedule = millis() + SIGNAL_PROPAGATION_DELAY;
}

void secondary(ExitSignal::Data::SignalState* signal, byte channel) {
  Output::setMask((signal->state & 0x0f) << (channel * 4));
  signal->step = idle;
  signal->schedule = 0;
}
