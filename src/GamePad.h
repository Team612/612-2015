#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <Joystick.h>
#include <Buttons/Button.h>
#include <Buttons/JoystickButton.h>

#define GAMEPAD
class GamePad : public Joystick
{
public:
	/// Gamepad constructor
	/// @param isFlightStick boolean for if we are controlling with flight stuck
	/// @param port integer for what port the gamepad is using
	/// @param throttle float for value to multiply input by
	/// @param deadzone float for how much of the joysticks to ignore
	GamePad(bool isFlightStick, int port, float throttle = 1.0f, float deadzone = 0.1f);
	float GetLeftXRaw(); ///<  gets value of left joystick left-right direction, no filter
	float GetLeftXSmooth(); ///< gets value of left joystick left-right direection, w/ filter
	float GetRightXRaw(); ///< gets value of right joystick left-right direction, no filter
	float GetRightXSmooth(); ///< gets value of right joystick left-right direction, w/ filter
	float GetLeftYRaw(); ///< gets value of left joystick up-down direction, no filter
	float GetLeftYSmooth(); ///< gets value of left joystick up-down direction, w/ filter
	float GetRightYRaw(); ///< gets value of right joystick up-down direction, no filter
	float GetRightYSmooth();///< gets value of right joystick up-down direction, w/ filter
	/*float GetLeftBumperRaw();
	float GetLeftBumperSmooth();
	float GetRightBumperRaw();
	float GetRightBumperSmooth();*/
	float GetDPad(); ///< gets number of gamepad activated (doesn't work)
	bool  GetDPadUp();  ///< returns bool of up being pressed
	bool  GetDPadDown();///< returns bool of down being pressed
	bool  GetDPadLeft();  ///< returns bool of left being pressed
	bool  GetDPadRight();  ///< returns bool of right being pressed
	bool  GetButtonStateA(); ///< returns bool of A being pressed
	bool  GetButtonStateB(); ///< returns bool of B being pressed
	bool  GetButtonStateX(); ///< returns bool of X being pressed
	bool  GetButtonStateY(); ///< returns bool of Y being pressed
	bool  GetButtonStateLB(); ///< returns bool of left bumper being pressed
	bool  GetButtonStateRB(); ///< returns bool of right bumper being pressed
	
	JoystickButton* ButtonA            = new JoystickButton(this, Button_A); ///< inits object for button A
	JoystickButton* ButtonB            = new JoystickButton(this, Button_B); ///< inits object for button B
	JoystickButton* ButtonX            = new JoystickButton(this, Button_X); ///< inits object for button X
	JoystickButton* ButtonY            = new JoystickButton(this, Button_Y); ///< inits object for button Y
	JoystickButton* StartButton        = new JoystickButton(this, Button_START); ///< inits object for start button
	JoystickButton* BackButton         = new JoystickButton(this, Button_BACK); ///< inits object for back button
	JoystickButton* LeftShoulder       = new JoystickButton(this, Button_SHOULDER_LEFT); ///< inits object for left bumper
	JoystickButton* RightShoulder      = new JoystickButton(this, Button_SHOULDER_RIGHT);///< inits object for right bumper
	JoystickButton* LeftStickClick     = new JoystickButton(this, Button_LEFT_STICK); ///< inits object for left stick
	JoystickButton* RightStickClick    = new JoystickButton(this, Button_RIGHT_STICK); ///< inits object for right stick
	JoystickButton* LeftTriggerClick   = new JoystickButton(this, Button_TRIGGER_LEFT);///< inits object for left trigger
	JoystickButton* RightTriggerClick  = new JoystickButton(this, Button_TRIGGER_RIGHT);///< inits object for right trigger

	 bool isFStick; ///< bool if flight stick is being used
private:
	// Axis Ports

	 int AXIS_LEFT_X; ///< value for left joystick left-right
	 int AXIS_LEFT_Y; ///< value for left joystick up-down
	 int AXIS_RIGHT_X; ///< value for right joystick left-right
	 int AXIS_RIGHT_Y; ///< value for right joystick up-down

	 const int AXIS_TRIGGER_L  = 2; ///< port for left trigger
	 const int 	AXIS_TRIGGER_R  = 3; ///< port for right trigger

		// Buttons Numbers
	 const int 	Button_A = 1; ///< port for A button
	 const int Button_B = 2; ///< port for B button
	 const int Button_X = 3; ///< port for X button
	 const int Button_Y = 4; ///< port for y button
	 const int 	Button_SHOULDER_LEFT = 5; ///< port for left shoulder
	 const int 	Button_SHOULDER_RIGHT = 6; ///< port for right shoulder
	 const int Button_TRIGGER_LEFT = 7; ///< port for left trigger
	 const int 	Button_TRIGGER_RIGHT = 8; ///< port for right trigger
	 const int 	Button_BACK = 10; ///< port for back button
	 const int Button_START = 9; ///< port for start button
	 const int 	Button_LEFT_STICK = 11; ///< port for left stick
	 const int 	Button_RIGHT_STICK = 12; ///< port for right stick

	void SetThrottle(float throttle); ///< @param throttle settles throttle
	void SetDeadZone(float deadzone); ///< @param deadzone set deadzone

	float DEADZONE = 0.25f; ///< The value for the Joystick deadzone
	float THROTTLE = 1.0f;  ///< The value for the Joystick throttle

	// Private internal methods for smoothing joystick values
	/// Returns if joystick value is within deadzone
	/// @param raw joystickw value to be tested to see if it's in the deadzone
	bool inDeadZone(float raw);
	float SmoothValue(float raw);
};

#endif
