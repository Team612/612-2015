#include "SmoothJoystick.h"
#include "../RobotMap.h"
#include "WPILib.h"

SmoothJoystick::SmoothJoystick()
{
}




//Below, JoystickHand is used to see which joystick you want. left = 0, right = 1
float SmoothJoystick::GetValue(int JoystickHand, int Axis) //Axis is used to find out whether you want y or x axis. x = 0, y = 1
{
	if (JoystickHand == 0) //Check to see if it is the left hand
	{
		Value = left_joystick->GetRawAxis(Axis);
	}
	else if (JoystickHand == 1) //Check to see if it is the right hand
	{
		Value = right_joystick->GetRawAxis(Axis);
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
