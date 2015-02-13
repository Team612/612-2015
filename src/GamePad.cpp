#include <Joystick.h>
#include "GamePad.h"

GamePad::GamePad(int port) : Joystick(port)
{
}

float GamePad::getLeftX()
{
	return GetRawAxis(AXIS_LEFT_X);
}

float GamePad::getRightX() {
	return GetRawAxis(AXIS_RIGHT_X);
}

float GamePad::getLeftY() {
	return GetRawAxis(AXIS_LEFT_Y);
}

float GamePad::getRightY() {
	return GetRawAxis(AXIS_RIGHT_Y);
}

bool GamePad::getButtonStateA() {
	return GetRawButton(Button_A);
}

bool GamePad::getButtonStateB() {
	return GetRawButton(Button_B);
}

bool GamePad::getButtonStateX() {
	return GetRawButton(Button_X);
}

bool GamePad::getButtonStateY() {
	return GetRawButton(Button_Y);
}

JoystickButton* GamePad::getButtonA() {
	return new JoystickButton(this, Button_A);
}

JoystickButton* GamePad::getButtonB() {
	return new JoystickButton(this, Button_B);
}

JoystickButton* GamePad::getButtonX() {
	return new JoystickButton(this, Button_X);
}

JoystickButton* GamePad::getButtonY() {
	return new JoystickButton(this, Button_Y);
}

/**
 * Return the DPad axis positions.
 */
float GamePad::getDPadX() {
	return GetRawAxis(AXIS_DPAD);
}

/**
 * DPad Left and Right only
 * WPILIB cannot access the vertical axis of the Logitech Game Controller Dpad
 */

bool GamePad::getDPadLeft() {
	float x = getDPadX();
	return (x < -0.5);
}

bool GamePad::getDPadRight() {
	float x = getDPadX();
	return (x > 0.5);
}

/**
 * Gets the state of the Start JoystickButton*
 * @return the state of the Start JoystickButton*
 */
JoystickButton* GamePad::getStartButton() {
	return new JoystickButton(this, Button_START);
}

JoystickButton* GamePad::getBackButton() {
	return new JoystickButton(this, Button_BACK);
}

/**
 * Gets the state of the left shoulder
 * @return the state of the left shoulder
 */
JoystickButton* GamePad::getLeftShoulder() {
	return new JoystickButton(this, Button_SHOULDER_LEFT);
}

/**
 * Gets the state of the right shoulder
 * @return the state of the right shoulder
 */
JoystickButton* GamePad::getRightShoulder() {
	return new JoystickButton(this, Button_SHOULDER_RIGHT);
}

JoystickButton* GamePad::getLeftStickClick() {
	return new JoystickButton(this, Button_LEFT_STICK);
}

JoystickButton* GamePad::getRightStickClick() {
	return new JoystickButton(this, Button_RIGHT_STICK);
}

JoystickButton* GamePad::getLeftTriggerClick() {
	return new JoystickButton(this, Button_TRIGGER_LEFT);
}

JoystickButton* GamePad::getRightTriggerClick() {
	return new JoystickButton(this, Button_TRIGGER_RIGHT);
}
