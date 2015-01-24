#include "SmoothJoystick.h"
#include "../RobotMap.h"

SmoothJoystick::SmoothJoystick() :
		Subsystem("SmoothJoystick")
{
}

void SmoothJoystick::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


//Below, JoystickHand is used to see which joystick you want. left = 0, right = 1
float SmoothJoystick::GetValue(int JoystickHand, int Axis) //Axis is used to find out whether you want y or x axis. x = 0, y = 1
{

	if (Axis == 0) //Check to see if it is the x axis you want
	{
		if (JoystickHand == 0) //Check to see if it is the left hand
		{
			Value = joystick->GetX(0);
		}
		else if (JoystickHand == 1) //Check to see if it is the right hand
		{
			Value = joystick->GetX(1);
		}
		else
		{
			return 0.0; //In case arguments are not appropriate
		}
	}
	else if (Axis == 1) //Check to see if it is the y axis you want
	{
		if (JoystickHand == 0) //Check to see if it is the left hand
		{
			Value = joystick->GetY(0);
		}
		else if (JoystickHand == 1) //Check to see if it is the right hand
		{
			Value = joystick->GetY(1);
		}
		else
		{
			return 0.0; //In case arguments are not appropriate
		}
		Value *= -1; //Used to reverse the y value cause up was negative and down was positive (CONFUSING RIGHT?)
	}
	else
	{
		return 0.0; //In case arguments are not appropriate
	}

	if (Value <= DeadZone)
	{
		return 0.0; //To filter signals
	}

	return Value; //Return the value you want
}
