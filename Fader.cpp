#include "Fader.hpp"

Fader::Fader(
  int pin_motor_enable,
  int pin_motor_direction_a,
  int pin_motor_direction_b,
  int pin_position
) :
  _pin_motor_enable(pin_motor_enable),
  _pin_motor_direction_a(pin_motor_direction_a),
  _pin_motor_direction_b(pin_motor_direction_b),
  _pin_position(pin_position)
{
  pinMode(this->_pin_motor_enable ,OUTPUT);
  pinMode(this->_pin_motor_direction_a ,OUTPUT);
  pinMode(this->_pin_motor_direction_b ,OUTPUT);
  pinMode(this->_pin_position ,INPUT);

  this->set_new_goal();
}

void Fader::update(void) {
  if (!this->_is_busy) return;
  
  this->_position = analogRead(this->_pin_position);
  int diff = this->_position - this->_goal;
  // Serial.println(this->_position);

  if (diff > 0) {
    digitalWrite(this->_pin_motor_direction_a, HIGH);
    digitalWrite(this->_pin_motor_direction_b, LOW);
  } else if (diff < 0) {
    digitalWrite(this->_pin_motor_direction_a, LOW);
    digitalWrite(this->_pin_motor_direction_b, HIGH);
  } else {
    digitalWrite(this->_pin_motor_enable, LOW);
    this->_is_busy = false;   
  }
}

#define DISCRETE_VALUES 9

void Fader::set_new_goal(void) {
  int discrete_value = random(0, DISCRETE_VALUES);
  this->_goal = constrain(
    discrete_value * (1024 / (DISCRETE_VALUES - 1)),
    0,
    1023
  );
  Serial.println(discrete_value);
  this->_is_busy = true;
  digitalWrite(this->_pin_motor_enable, HIGH);
}
