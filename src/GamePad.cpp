#include <Joystick.h>
#include "GamePad.h"

GamePad::GamePad(int port, float throttle, float deadzone) : Joystick(port)
{
	ButtonA            = new JoystickButton(this, Button_A);
	ButtonB            = new JoystickButton(this, Button_B);
	ButtonX            = new JoystickButton(this, Button_X);
	ButtonY            = new JoystickButton(this, Button_Y);
	StartButton        = new JoystickButton(this, Button_START);
	BackButton         = new JoystickButton(this, Button_BACK);
	LeftShoulder       = new JoystickButton(this, Button_SHOULDER_LEFT);
	RightShoulder      = new JoystickButton(this, Button_SHOULDER_RIGHT);
	LeftStickClick     = new JoystickButton(this, Button_LEFT_STICK);
	RightStickClick    = new JoystickButton(this, Button_RIGHT_STICK);
	LeftTriggerClick   = new JoystickButton(this, Button_TRIGGER_LEFT);
	RightTriggerClick  = new JoystickButton(this, Button_TRIGGER_RIGHT);
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
