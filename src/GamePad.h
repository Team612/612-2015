#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <Joystick.h>
#include <Buttons/Button.h>
#include <Buttons/JoystickButton.h>

#define GAMEPAD
class GamePad : public Joystick
{
public:
	GamePad(bool isFlightStick, int port, float throttle = 1.0f, float deadzone = 0.1f);
	float GetLeftXRaw();
	float GetLeftXSmooth();
	float GetRightXRaw();
	float GetRightXSmooth();
	float GetLeftYRaw();
	float GetLeftYSmooth();
	float GetRightYRaw();
	float GetRightYSmooth();
	/*float GetLeftBumperRaw();
	float GetLeftBumperSmooth();
	float GetRightBumperRaw();
	float GetRightBumperSmooth();*/
	float GetDPad();
	bool  GetDPadUp();
	bool  GetDPadDown();
	bool  GetDPadLeft();
	bool  GetDPadRight();
	bool  GetButtonStateA();
	bool  GetButtonStateB();
	bool  GetButtonStateX();
	bool  GetButtonStateY();
	bool  GetButtonStateLB();
	bool  GetButtonStateRB();

	 JoystickButton* ButtonA            = new JoystickButton(this, Button_A);
	 JoystickButton* ButtonB            = new JoystickButton(this, Button_B);
	 JoystickButton* ButtonX            = new JoystickButton(this, Button_X);
	 JoystickButton* ButtonY            = new JoystickButton(this, Button_Y);
	 JoystickButton* StartButton        = new JoystickButton(this, Button_START);
	 JoystickButton* BackButton         = new JoystickButton(this, Button_BACK);
	 JoystickButton* LeftShoulder       = new JoystickButton(this, Button_SHOULDER_LEFT);
	 JoystickButton* RightShoulder      = new JoystickButton(this, Button_SHOULDER_RIGHT);
	 JoystickButton* LeftStickClick     = new JoystickButton(this, Button_LEFT_STICK);
	 JoystickButton* RightStickClick    = new JoystickButton(this, Button_RIGHT_STICK);
	 JoystickButton* LeftTriggerClick   = new JoystickButton(this, Button_TRIGGER_LEFT);
	 JoystickButton* RightTriggerClick  = new JoystickButton(this, Button_TRIGGER_RIGHT);

	 bool isFStick;
private:
	// Axis Ports

	 int AXIS_LEFT_X;
	 int AXIS_LEFT_Y;
	 int AXIS_RIGHT_X;
	 int AXIS_RIGHT_Y;

	 const int AXIS_TRIGGER_L  = 2;
	 const int 	AXIS_TRIGGER_R  = 3;

		// Buttons Numbers
	 const int 	Button_A = 1;
	 const int Button_B = 2;
	 const int Button_X = 3;
	 const int Button_Y = 4;
	 const int 	Button_SHOULDER_LEFT = 5;
	 const int 	Button_SHOULDER_RIGHT = 6;
	 const int Button_TRIGGER_LEFT = 7;
	 const int 	Button_TRIGGER_RIGHT = 8;
	 const int 	Button_BACK = 10;
	 const int Button_START = 9;
	 const int 	Button_LEFT_STICK = 11;
	 const int 	Button_RIGHT_STICK = 12;
	 const int 	Button_MODE = -1;
	 const int Button_XBOX = -1;

	void SetThrottle(float throttle);
	void SetDeadZone(float deadzone);

	float DEADZONE = 0.25f; // The value for the Joystick deadzone
	float THROTTLE = 1.0f;  // The value for the Joystick throttle

	// Private internal methods for smoothing joystick values
	bool inDeadZone(float raw);
	float SmoothValue(float raw);
};

#endif
