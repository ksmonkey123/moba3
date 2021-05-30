#include "logic.h"
#include "switches.h"
#include "output.h"
#include "utils.h"
#include "settings.h"

void Switches::init() {
  Output::Config conf = { .mask = 0x3f3f };
  Output::init(0, &conf);

  memset(&_logicData.switches, 0, sizeof(Data));
  _logicData.switches.driveTime = _chipConfig.customFlag ? SWITCH_DRIVE_TIME_HIGH : SWITCH_DRIVE_TIME_LOW;
}

void Switches::process(char* buffer, char length) {
  if ((length % 2) != 0 || length > 12) {
    return;
  }

  for (byte i = 0; i < length; i += 2) {
    char channelId = buffer[i];
    if (channelId < '1' || channelId > '6') {
      return;
    }

    ChannelState* channel = _logicData.switches.channel + (channelId - '1');

    switch (buffer[i+1]) {
      case 'a':
        channel->pendingState = 1;
        break;
      case 'b':
        channel->pendingState = 2;
    }
  }
}

uint16_t determineBaseMaskBit(uint8_t channelId) {
  switch (channelId) {
    case 0:
      return 0x0001;
    case 1:
      return 0x0004;
    case 2:
      return 0x0010;
    case 3:
      return 0x0100;
    case 4:
      return 0x0400;
    case 5:
      return 0x1000;
  }
}

void Switches::tick() {
  uint16_t setMask = 0;
  uint16_t clearMask = 0;
  uint32_t time = millis();
  for (byte i = 0; i < 6; i++) {
    ChannelState* channel = _logicData.switches.channel + i;

    uint32_t start = channel->startMillis;

    if (start != 0 && start + _logicData.switches.driveTime < time) {
      uint16_t mask = determineBaseMaskBit(i);
      clearMask |= mask;
      clearMask |= (mask << 1);
      channel->startMillis = 0;
    }

    uint8_t pending = channel->pendingState;
    if (start == 0 && pending != channel->state) {
      channel->state = pending;
      channel->startMillis = time;
      uint16_t mask = determineBaseMaskBit(i);
      setMask |= (mask << (channel->pendingState - 1));
    }
  }

  Output::clearMask(clearMask);
  Output::setMask(setMask);
}