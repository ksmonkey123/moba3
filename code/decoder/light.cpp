#include "logic.h"
#include "light.h"
#include "output.h"
#include "utils.h"

void Light::init() {
  Output::Config conf = { .mask = (_chipConfig.type == Config::Type::EXIT) ? 0x001f : 0xffff };
  Output::init(0, &conf);
}

void Light::process(char* buffer, char length) {
  switch(buffer[0]) {
    case 'r':
      Output::clear();
      break;
    case 'o':
      Output::setState(-1);
      break;
    case 's':
      Output::setMask(Util::decodeHexString(buffer + 1, length - 1));
      break;
    case 'c':
      Output::clearMask(Util::decodeHexString(buffer + 1, length - 1));
      break;
    case 'u':
      Output::setState(Util::decodeHexString(buffer + 1, length - 1));
      break;
    default:
      break;
  }
}