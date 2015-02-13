#include <Joystick.h>
#include "GamePad.h"

GamePad::GamePad(int port) : Joystick(port)
{
	ButtonA = new JoystickButton(this, Button_A);
	ButtonB = new JoystickButton(this, Button_B);
	ButtonX = new JoystickButton(this, Button_X);
	ButtonY = new JoystickButton(this, Button_Y);
	StartButton = new JoystickButton(this, Button_START);
	BackButton = new JoystickButton(this, Button_BACK);
	LeftShoulder = new JoystickButton(this, Button_SHOULDER_LEFT);
	RightShoulder = new JoystickButton(this, Button_SHOULDER_RIGHT);
	LeftStickClick = new JoystickButton(this, Button_LEFT_STICK);
	RightStickClick = new JoystickButton(this, Button_RIGHT_STICK);
	LeftTriggerClick = new JoystickButton(this, Button_TRIGGER_LEFT);
	RightTriggerClick = new JoystickButton(this, Button_TRIGGER_RIGHT);
}

float GamePad::getLeftX()
{
	return GetRawAxis(AXIS_LEFT_X);
}

float GamePad::getRightX()
{
	return GetRawAxis(AXIS_RIGHT_X);
}

float GamePad::getLeftY()
{
	return GetRawAxis(AXIS_LEFT_Y);
}

float GamePad::getRightY()
{
	return GetRawAxis(AXIS_RIGHT_Y);
}

bool GamePad::getButtonStateA()
{
	return GetRawButton(Button_A);
}

bool GamePad::getButtonStateB()
{
	return GetRawButton(Button_B);
}

bool GamePad::getButtonStateX()
{
	return GetRawButton(Button_X);
}

bool GamePad::getButtonStateY()
{
	return GetRawButton(Button_Y);
}

float GamePad::getDPad()
{
	return GetPOV();
}

bool GamePad::getDPadLeft()
{
	float dpad = getDPad();
	return (dpad < -0.5);
}

bool GamePad::getDPadRight()
{
	float dpad = getDPad();
	return (dpad > 0.5);
}

bool GamePad::getDPadUp()
{
	float dpad = getDPad();
	return (dpad > 0.5);
}

bool GamePad::getDPadDown()
{
	float dpad = getDPad();
	return (dpad > -0.5);
}

