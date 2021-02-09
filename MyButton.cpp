#include "MyButton.hpp"

MyButton::MyButton(int pin, void (*onButtonPress)(void)) :
  _onButtonPress(onButtonPress)
{
  pinMode(pin, INPUT_PULLUP);
  this->_debouncer.attach(pin);
  this->_debouncer.interval(5); // 5 ms input delay
  this->_prevButtonState = HIGH;
}

void MyButton::update(void) {
  this->_debouncer.update();
  int buttonState = this->_debouncer.read();

  if (this->_prevButtonState != buttonState) {
    // on button press
    if (buttonState == LOW && this->_onButtonPress) {
      this->_onButtonPress();
    }
    this->_prevButtonState = buttonState;
  }
}
