#include "OI.h"

OI::OI()
{
	left_joystick = new Joystick(0);
	right_joystick = new Joystick(1);

	button_a = new JoystickButton(1);
	button_b = new JoystickButton(2);
	button_x = new JoystickButton(3);
	button_y = new JoystickButton(4);
}
