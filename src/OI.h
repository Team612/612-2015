
#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
public:
	OI();

	Joystick* right_joystick;
	Joystick* left_joystick;
	Joystick* xbox_controller;

	JoystickButton* button_a;
	JoystickButton* button_b;
	JoystickButton* button_x;
	JoystickButton* button_y;

};

#endif
