
#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <Buttons/Button.h>
#include <Joystick.h>

class OI
{
public:
	OI();
/*
	Joystick* right_joystick;//for the right joystick
	Joystick* left_joystick;//for the left joystick
	Joystick* xbox_controller;//for the xbox controller

	JoystickButton* button_a;//for the A button
	JoystickButton* button_b;//for the B button
	JoystickButton* button_x;//for the X button
	JoystickButton* button_y;//for the Y button
*/
	//Elevator Operator Buttons

	Joystick* gunner_controller;
	Joystick* driver_controller;

	JoystickButton* button_x;
	JoystickButton* button_y;
	JoystickButton* button_b;



};

#endif
