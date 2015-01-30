/*
 * SmoothJoystick.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: zachary
 */

#include <SmoothJoystick.h>

SmoothJoystick::SmoothJoystick(int port):Joystick(port)
{
	// TODO Auto-generated constructor stub

}

SmoothJoystick::~SmoothJoystick()
{
	// TODO Auto-generated destructor stub
}

float SmoothJoystick::GetModValue(int axis)
{
	float val = GetRawAxis(axis);
	if (val < TOLORANCE && val > -TOLORANCE)
	{
		return 0.0f;
	}
	else
	{
		return val*THROTTLE;
	}
}
