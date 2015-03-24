#include <Joystick.h>
#include "GamePad.h"

GamePad::GamePad(bool isFlightStick, int port, float throttle, float deadzone) : Joystick(port)
{
	// Axis Ports
	if(!isFlightStick)
	{
		AXIS_LEFT_X     = 0;
		AXIS_LEFT_Y     = 1;
		AXIS_RIGHT_X    = 4;
		AXIS_RIGHT_Y    = 5;
	}
	else
	{
		AXIS_LEFT_X     = 0;
		AXIS_LEFT_Y     = 1;
		AXIS_RIGHT_X    = 2;
		AXIS_RIGHT_Y    = 3;
	}
	stickType = isFlightStick;
}

float GamePad::GetLeftXRaw()
{
	return GetRawAxis(AXIS_LEFT_X);
}

float GamePad::GetLeftXSmooth()
{
	return SmoothValue(GetLeftXRaw());
}

float GamePad::GetRightXRaw()
{
	return GetRawAxis(AXIS_RIGHT_X) * -1;
}

float GamePad::GetRightXSmooth()
{
	return SmoothValue(GetRightXRaw());
}

float GamePad::GetLeftYRaw()
{
	return GetRawAxis(AXIS_LEFT_Y) * -1;
}

float GamePad::GetLeftYSmooth()
{
	return SmoothValue(GetLeftYRaw());
}

float GamePad::GetRightYRaw()
{
	return GetRawAxis(AXIS_RIGHT_Y);
}

float GamePad::GetRightYSmooth()
{
	return SmoothValue(GetRightYRaw());
}
/*float GamePad::GetLeftBumperRaw()
{
	return GetRawAxis(AXIS_RIGHT_Y);
}

float GamePad::GetLeftBumperSmooth()
{
	return SmoothValue(GetRightYRaw());
}

float GamePad::GetRightBumperRaw()
{
	return GetRawAxis(AXIS_RIGHT_Y);
}

float GamePad::GetRightBumperSmooth()
{
	return SmoothValue(GetRightYRaw());
}*/

float GamePad::GetDPad()
{
	return GetPOV();
}

bool GamePad::GetDPadUp()
{
	float dpad = GetDPad();
	return (dpad > 0.5);
}

bool GamePad::GetDPadDown()
{
	float dpad = GetDPad();
	return (dpad > -0.5);
}

bool GamePad::GetDPadLeft()
{
	float dpad = GetDPad();
	return (dpad < -0.5);
}

bool GamePad::GetDPadRight()
{
	float dpad = GetDPad();
	return (dpad > 0.5);
}

bool GamePad::GetButtonStateA()
{
	return GetRawButton(Button_A);
}

bool GamePad::GetButtonStateB()
{
	return GetRawButton(Button_B);
}

bool GamePad::GetButtonStateX()
{
	return GetRawButton(Button_X);
}

bool GamePad::GetButtonStateY()
{
	return GetRawButton(Button_Y);
}
bool GamePad::GetButtonStateLB()
{
	return GetRawButton(Button_SHOULDER_LEFT);
}
bool GamePad::GetButtonStateRB()
{
	return GetRawButton(Button_SHOULDER_RIGHT);
}

void GamePad::SetThrottle(float throttle)
{
	THROTTLE = throttle;
}
void GamePad::SetDeadZone(float deadzone)
{
	DEADZONE = deadzone;
}

// Private internal methods for smoothing joystick values
bool GamePad::inDeadZone(float raw)
{
	return (raw < DEADZONE && raw > -DEADZONE);
}

float GamePad::SmoothValue(float raw)
{
	if(inDeadZone(raw))
		return 0.0f;
	return raw * THROTTLE;
}
