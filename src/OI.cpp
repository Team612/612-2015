#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	/*
	xbox_controller = new Joystick(XBOX_CONTROLLER); //the actual xbox controller (don't know which port it is)
	left_joystick = new Joystick(LEFT_JOYSTICK); //the left joystick
	right_joystick = new Joystick(RIGHT_JOYSTICK);//the right joystick

	button_a = new JoystickButton(xbox_controller,BUTTON_A);//A button
	button_b = new JoystickButton(xbox_controller,BUTTON_B);//B button
	button_x = new JoystickButton(xbox_controller,BUTTON_X);//X button
	button_y = new JoystickButton(xbox_controller,BUTTON_Y);//Y button
	*/
	//TODO find the right port stuff and fix it
	//Buttons

	gunner_controller = new Joystick(1);
	driverLeft = new Joystick(2);
	driverRight = new Joystick(2);

	button_b = new JoystickButton(gunner_controller,BUTTON_B);
	button_x = new JoystickButton(gunner_controller,BUTTON_X);
	button_y = new JoystickButton(gunner_controller,BUTTON_Y);

}
