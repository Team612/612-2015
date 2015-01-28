#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
		Joystick *right_joystick;
		Joystick *left_joystick;

		JoystickButton *button_a;
		JoystickButton *button_b;
		JoystickButton *button_x;
		JoystickButton *button_y;


public:
	OI();

};

#endif
