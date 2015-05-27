#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <Joystick.h>
#include <Buttons/Button.h>
#include <Buttons/JoystickButton.h>

#define GAMEPAD
class GamePad : public Joystick
{
public:
	GamePad(bool isFlightStick, int port, float throttle = 1.0f, float deadzone = 0.1f); ///< inits gamepad
	float GetLeftXRaw(); ///< @fn gets value of left joystick left-right direction, no filter
	float GetLeftXSmooth(); ///< @fn gets value of left joystick left-right direection, w/ filter
	float GetRightXRaw(); ///< @fn gets value of right joystick left-right direction, no filter
	float GetRightXSmooth(); ///< @fn gets value of right joystick left-right direction, w/ filter
	float GetLeftYRaw(); ///< @fn gets value of left joystick up-down direction, no filter
	float GetLeftYSmooth(); ///< @fn gets value of left joystick up-down direction, w/ filter
	float GetRightYRaw(); ///< @fn gets value of right joystick up-down direction, no filter
	float GetRightYSmooth();///< @fn gets value of right joystick up-down direction, w/ filter
	/*float GetLeftBumperRaw();
	float GetLeftBumperSmooth();
	float GetRightBumperRaw();
	float GetRightBumperSmooth();*/
	float GetDPad(); ///< @fn gets number of gamepad activated (doesn't work)
	bool  GetDPadUp();  ///< @fn returns bool of up being pressed
	bool  GetDPadDown();///< @fn returns bool of down being pressed
	bool  GetDPadLeft();  ///< @fn returns bool of left being pressed
	bool  GetDPadRight();  ///< @fn returns bool of right being pressed
	bool  GetButtonStateA(); ///< @fn returns bool of A being pressed
	bool  GetButtonStateB(); ///< @fn returns bool of B being pressed
	bool  GetButtonStateX(); ///< @fn returns bool of X being pressed
	bool  GetButtonStateY(); ///< @fn returns bool of Y being pressed
	bool  GetButtonStateLB(); ///< @fn returns bool of left bumper being pressed
	bool  GetButtonStateRB(); ///< @fn returns bool of right bumper being pressed

	 JoystickButton* ButtonA            = new JoystickButton(this, Button_A); ///< @var inits object for button A
	 JoystickButton* ButtonB            = new JoystickButton(this, Button_B); ///< @var inits object for button B
	 JoystickButton* ButtonX            = new JoystickButton(this, Button_X); ///< @var inits object for button X
	 JoystickButton* ButtonY            = new JoystickButton(this, Button_Y); ///< @var inits object for button Y
	 JoystickButton* StartButton        = new JoystickButton(this, Button_START); ///< @var inits object for start button
	 JoystickButton* BackButton         = new JoystickButton(this, Button_BACK); ///< @var inits object for back button
	 JoystickButton* LeftShoulder       = new JoystickButton(this, Button_SHOULDER_LEFT); ///< @var inits object for left bumper
	 JoystickButton* RightShoulder      = new JoystickButton(this, Button_SHOULDER_RIGHT);///< @var inits object for right bumper
	 JoystickButton* LeftStickClick     = new JoystickButton(this, Button_LEFT_STICK); ///< @var inits object for left stick
	 JoystickButton* RightStickClick    = new JoystickButton(this, Button_RIGHT_STICK); ///< @var inits object for right stick
	 JoystickButton* LeftTriggerClick   = new JoystickButton(this, Button_TRIGGER_LEFT);///< @var inits object for left trigger
	 JoystickButton* RightTriggerClick  = new JoystickButton(this, Button_TRIGGER_RIGHT);///< @var inits object for right trigger

	 bool isFStick; ///< @var bool if flight stick is being used
private:
	// Axis Ports

	 int AXIS_LEFT_X; ///< @var value for left joystick left-right
	 int AXIS_LEFT_Y; ///< @var value for left joystick up-down
	 int AXIS_RIGHT_X; ///< @var value for right joystick left-right
	 int AXIS_RIGHT_Y; ///< @var value for right joystick up-down

	 const int AXIS_TRIGGER_L  = 2; ///< @var port for left trigger
	 const int 	AXIS_TRIGGER_R  = 3; ///< @var port for right trigger

		// Buttons Numbers
	 const int 	Button_A = 1; ///< @var port for A button
	 const int Button_B = 2; ///< @var port for B button
	 const int Button_X = 3; ///< @var port for X button
	 const int Button_Y = 4; ///< @var port for y button
	 const int 	Button_SHOULDER_LEFT = 5; ///< @var port for left shoulder
	 const int 	Button_SHOULDER_RIGHT = 6; ///< @var port for right shoulder
	 const int Button_TRIGGER_LEFT = 7; ///< @var port for left trigger
	 const int 	Button_TRIGGER_RIGHT = 8; ///< @var port for right trigger
	 const int 	Button_BACK = 10; ///< @var port for back button
	 const int Button_START = 9; ///< @var port for start button
	 const int 	Button_LEFT_STICK = 11; ///< @var port for left stick
	 const int 	Button_RIGHT_STICK = 12; ///< @var port for right stick

	void SetThrottle(float throttle); ///< @fn @param throttle settles throttle
	void SetDeadZone(float deadzone); ///< @fn @param deadzone set deadzone

	float DEADZONE = 0.25f; ///< @var The value for the Joystick deadzone
	float THROTTLE = 1.0f;  ///< @var The value for the Joystick throttle

	// Private internal methods for smoothing joystick values
	bool inDeadZone(float raw);
	float SmoothValue(float raw);
};

#endif
