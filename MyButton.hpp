#ifndef MY_BUTTON_HPP
#define MY_BUTTON_HPP

#include "Arduino.h"

/*
  See https://github.com/thomasfredericks/Bounce2
*/
#define BOUNCE_LOCK_OUT
#include <Bounce2.h>

class MyButton
{
  public:
    MyButton(int pin, void (*onButtonPress)(void));
    void        update(void);
  
  private:
    Bounce      _debouncer;
    int         _prevButtonState;
    void        (*_onButtonPress)(void);
};

#endif
