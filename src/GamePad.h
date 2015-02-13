#ifndef GamePad_H
#define GamePad_H

#include <Joystick.h>
#include <Buttons/Button.h>
#include <Buttons/JoystickButton.h>

class GamePad : public Joystick
{
private:
	// Axis ports
	const int AXIS_LEFT_X = 1;
	const int AXIS_LEFT_Y = 2;
	const int AXIS_SHOULDER = 3;
	const int AXIS_RIGHT_X = 4;
	const int AXIS_RIGHT_Y = 5;
	const int AXIS_DPAD = 6;

	// Buttons
	const int Button_A = 2;
	const int Button_B = 3;
	const int Button_X = 1;
	const int Button_Y = 4;
	const int Button_SHOULDER_LEFT = 5;
	const int Button_SHOULDER_RIGHT = 6;
	const int Button_TRIGGER_LEFT = 7;
	const int Button_TRIGGER_RIGHT = 8;
	const int Button_BACK = 9;
	const int Button_START = 10;
	const int Button_LEFT_STICK = 11;
	const int Button_RIGHT_STICK = 12;
	const int Button_MODE = -1;
	const int Button_XBOX = -1;

public:
	GamePad(int port);
	float getLeftX();
	float getRightX();
	float getLeftY();
	float getRightY();
	bool getButtonStateA();
	bool getButtonStateB();
	bool getButtonStateX();
	bool getButtonStateY();
	JoystickButton* getButtonA();
	JoystickButton* getButtonB();
	JoystickButton* getButtonX();
	JoystickButton* getButtonY();
	float getDPadX();
	bool getDPadLeft();
	bool getDPadRight();
	JoystickButton* getStartButton();
	JoystickButton* getBackButton();
	JoystickButton* getLeftShoulder();
	JoystickButton* getRightShoulder();
	JoystickButton* getLeftStickClick();
	JoystickButton* getRightStickClick();
	JoystickButton* getLeftTriggerClick();
	JoystickButton* getRightTriggerClick();
};

#endif
