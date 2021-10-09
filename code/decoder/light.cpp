#include "logic.h"
#include "light.h"
#include "output.h"
#include "utils.h"

void Light::init() {
  Output::init(0, nullptr);
}

static boolean validate(char length) {
  return length == 5;
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
      if (validate(length)) {
        Output::setMask(Util::decodeHexString16(buffer + 1));
      }
      break;
    case 'c':
      if (validate(length)) {
        Output::clearMask(Util::decodeHexString16(buffer + 1));
      }
      break;
    case 'u':
      if (validate(length)) {
        Output::setState(Util::decodeHexString16(buffer + 1));
      }
      break;
    default:
      break;
  }
}
