#include "OI.h"

OI::OI()
{
	xbox_controller = new Joystick(3);
	left_joystick = new Joystick(0);
	right_joystick = new Joystick(1);

	button_a = new JoystickButton(xbox_controller,1);
	button_b = new JoystickButton(xbox_controller,2);
	button_x = new JoystickButton(xbox_controller,3);
	button_y = new JoystickButton(xbox_controller,4);
}
