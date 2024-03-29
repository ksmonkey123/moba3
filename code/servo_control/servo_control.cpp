#include <Arduino.h>
#include <Servo.h>

#include "settings.h"

Servo servo;

void startLED(uint8_t led) {
  pinMode(led, OUTPUT);
  digitalWrite(led, true);
}

void setup() {
  pinMode(PIN_TOGGLE, INPUT_PULLUP);
  pinMode(PIN_TRIGGER_A, INPUT_PULLUP);
  pinMode(PIN_TRIGGER_B, INPUT_PULLUP);

  startLED(PIN_LED_A);
  startLED(PIN_LED_B);
  startLED(PIN_LED_C);

  servo.attach(PIN_SERVO);
  servo.writeMicroseconds(1500);

  delay(BOOT_DELAY_MS);
  
  digitalWrite(PIN_LED_A, false);
  digitalWrite(PIN_LED_B, false);
}

static int8_t channel = -1;
unsigned long lastTick;

static struct State {
  int8_t channel = -1;
  int data;
} state;

void tick() {
  boolean trigger = lastTick + 200 > millis();

  if (channel != state.channel || !trigger) {
    state.channel = channel;
    state.data = analogRead(channel == 0 ? PIN_CALIBRATION_A : PIN_CALIBRATION_B);
  }

  digitalWrite(PIN_LED_C, trigger);
  servo.writeMicroseconds(988 + state.data);
}

void updateLED() {
  lastTick = millis();
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
