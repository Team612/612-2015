#include "OI.h"

OI::OI()
{
	xbox_controller = new Joystick(3); //the actual xbox controller (don't know which port it is)
	left_joystick = new Joystick(0); //the left joystick
	right_joystick = new Joystick(1);//the right joystick

	button_a = new JoystickButton(xbox_controller,1);//A button
	button_b = new JoystickButton(xbox_controller,2);//B button
	button_x = new JoystickButton(xbox_controller,3);//X button
	button_y = new JoystickButton(xbox_controller,4);//Y button
	//TODO find the right port stuff and fix it
}
