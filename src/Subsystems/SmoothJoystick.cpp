#include "Subsystems/SmoothJoystick.h"
#include "../RobotMap.h"
#include "WPILib.h"

SmoothJoystick::SmoothJoystick(int port):Joystick(port)
{
}

//Below, JoystickHand is used to see which joystick you want. left = 0, right = 1
float SmoothJoystick::GetValue(int axis) //Axis is used to find out whether you want y or x axis. x = 0, y = 1
{
	float value = 0.0; //Used to return the value wanted

	value = GetRawAxis(axis);
	if (value < DEADZONE && value > -DEADZONE)
	{
		return 0.0f;
	}
	else
	{
		return value*THROTTLE;
	}
}


