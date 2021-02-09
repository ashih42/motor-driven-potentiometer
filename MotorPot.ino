#include "config.h"
#include "MyButton.hpp"
#include "Fader.hpp"

Fader fader(
  PIN_FADER_MOTOR_ENABLE,
  PIN_FADER_MOTOR_DIRECTION_A,
  PIN_FADER_MOTOR_DIRECTION_B,
  PIN_FADER_POSITION
);

void set_fader_new_goal() {
  Serial.println("NEW GOAL");
  fader.set_new_goal();
}

MyButton button(PIN_BUTTON_0, set_fader_new_goal);

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial.println("SETUP OK");
}

void loop() {
  button.update();
  fader.update();
}
