#include "SmoothJoystick.h"
#include "../RobotMap.h"
#include "WPILib.h"

SmoothJoystick::SmoothJoystick()
{
}

//Below, JoystickHand is used to see which joystick you want. left = 0, right = 1
float SmoothJoystick::GetValue(int JoystickHand, int Axis) //Axis is used to find out whether you want y or x axis. x = 0, y = 1
{
	float value = 0.0; //Used to return the value wanted

	if (JoystickHand == 0) //Check to see if it is the left hand
	{
		value = left_joystick->GetRawAxis(Axis); //set the value for output
	}
	else if (JoystickHand == 1) //Check to see if it is the right hand
	{
		value = right_joystick->GetRawAxis(Axis); //set the value for output
	}
	else
	{
		return 0.0; //In case arguments are not appropriate
	}

	if (value <= DEAD_ZONE)
	{
		return 0.0; //To filter signals
	}

	value = (round(value*100))/100; //round to the nearest hundredth

	if (value > 1) //Make sure rounding or other stuff does not exceeds 1
	{
		value = 1.0;
	}

	if (value < -1) //Make sure rounding or other stuff does not make value less than -1
	{
		value = -1.0;
	}
	return value; //Return the value you want
}
