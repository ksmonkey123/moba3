#include <Arduino.h>
#include <Servo.h>

#include "settings.h"

Servo myservo;

void setup() {
  pinMode(PIN_LED_A, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  pinMode(PIN_TOGGLE, INPUT_PULLUP);
  pinMode(PIN_TRIGGER_A, INPUT_PULLUP);
  pinMode(PIN_TRIGGER_B, INPUT_PULLUP);
}

static int channel = -1;

void tick() {
  auto input = analogRead(channel == 0 ? PIN_CALIBRATION_A : PIN_CALIBRATION_B);
  myservo.writeMicroseconds(988 + input);
}

void updateLED() {
    myservo.attach(PIN_SERVO);
  if (channel == 0) {
    digitalWrite(PIN_LED_A, true);
    digitalWrite(PIN_LED_B, false);
  } else {
    digitalWrite(PIN_LED_A, false);
    digitalWrite(PIN_LED_B, true);
  }
}

void onClick() {
  channel = (channel + 1) % 2;
  updateLED();
}

void testButton() {
  static bool last = false;
  bool value = !digitalRead(PIN_TOGGLE);

  if (value && !last) {
    onClick();
  }

  last = value;
  
  if (!digitalRead(PIN_TRIGGER_A)) {
    channel = 0;
    updateLED();
  }
  if (!digitalRead(PIN_TRIGGER_B)) {
    channel = 1;
    updateLED();
  }

}

void loop() {
  testButton();
  if (channel >= 0) {
    tick();
  }
  delay(1);
}
