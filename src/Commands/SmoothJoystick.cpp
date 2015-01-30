#include "SmoothJoystick.h"
#include "../RobotMap.h"
#include "WPILib.h"

SmoothJoystick::SmoothJoystick()
//		Subsystem("SmoothJoystick")
{
}

/*void SmoothJoystick::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
}*/

// Put methods for controlling this subsystem
// here. Call these from Commands.


//Below, JoystickHand is used to see which joystick you want. left = 0, right = 1
float SmoothJoystick::GetValue(int JoystickHand, int Axis) //Axis is used to find out whether you want y or x axis. x = 0, y = 1
{
		if (JoystickHand == 0) //Check to see if it is the left hand
		{
			if (Axis == 0)
			{
				Value = left_joystick->GetRawAxis(0);
			}
			else if (Axis == 1)
			{
				Value = left_joystick->GetRawAxis(1);
			}
			else
			{
				return 0.0;
			}
		}
		else if (JoystickHand == 1) //Check to see if it is the right hand
		{
			if (Axis == 0)
			{
				Value = right_joystick->GetRawAxis(0);
			}
			else if (Axis == 1)
			{
				Value = right_joystick->GetRawAxis(1);
			}
			else
			{
				return 0.0;
			}
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
