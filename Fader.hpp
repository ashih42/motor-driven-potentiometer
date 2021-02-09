#ifndef FADER_HPP
#define FADER_HPP

#include "Arduino.h"

class Fader
{
  public:
    Fader(
      int pin_motor_enable,
      int pin_motor_direction_a,
      int pin_motor_direction_b,
      int pin_position
    );

    void        update(void);
    void        set_new_goal(void);
  
  private:
    int         _pin_motor_enable;
    int         _pin_motor_direction_a;
    int         _pin_motor_direction_b;
    int         _pin_position;

    int         _goal;
    int         _position;
    bool        _is_busy;
};

#endif
