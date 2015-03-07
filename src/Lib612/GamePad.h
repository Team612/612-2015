#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <Joystick.h>
#include <Buttons/Button.h>
#include <Buttons/JoystickButton.h>

namespace Lib612
{
	class GamePad : public Joystick
	{
	public:
		GamePad(int port, float throttle = 1.0f, float deadzone = 0.1f);
		float GetLeftXRaw();
		float GetLeftXSmooth();
		float GetRightXRaw();
		float GetRightXSmooth();
		float GetLeftYRaw();
		float GetLeftYSmooth();
		float GetRightYRaw();
		float GetRightYSmooth();
		float GetDPad();
		bool  GetDPadUp();
		bool  GetDPadDown();
		bool  GetDPadLeft();
		bool  GetDPadRight();
		bool  GetButtonStateA();
		bool  GetButtonStateB();
		bool  GetButtonStateX();
		bool  GetButtonStateY();

		void SetThrottle(float throttle);
		void SetDeadZone(float deadzone);

		JoystickButton* ButtonA;
		JoystickButton* ButtonB;
		JoystickButton* ButtonX;
		JoystickButton* ButtonY;
		JoystickButton* StartButton;
		JoystickButton* BackButton;
		JoystickButton* LeftShoulder;
		JoystickButton* RightShoulder;
		JoystickButton* LeftStickClick;
		JoystickButton* RightStickClick;
		JoystickButton* LeftTriggerClick;
		JoystickButton* RightTriggerClick;

	private:
		// Axis Ports
		const int AXIS_LEFT_X     = 0;
		const int AXIS_LEFT_Y     = 1;
		const int AXIS_RIGHT_X    = 4;
		const int AXIS_RIGHT_Y    = 5;
		const int AXIS_TRIGGER_L  = 2;
		const int AXIS_TRIGGER_R  = 3;

		// Buttons Numbers
		const int Button_A = 1;
		const int Button_B = 2;
		const int Button_X = 3;
		const int Button_Y = 4;
		const int Button_SHOULDER_LEFT = 5;
		const int Button_SHOULDER_RIGHT = 6;
		const int Button_TRIGGER_LEFT = 7;
		const int Button_TRIGGER_RIGHT = 8;
		const int Button_BACK = 10;
		const int Button_START = 9;
		const int Button_LEFT_STICK = 11;
		const int Button_RIGHT_STICK = 12;
		const int Button_MODE = -1;
		const int Button_XBOX = -1;

		float DEADZONE = 0.25f; // The value for the Joystick deadzone
		float THROTTLE = 1.0f;  // The value for the Joystick throttle

		// Private internal methods for smoothing joystick values
		bool inDeadZone(float raw);
		float SmoothValue(float raw);
	};
}
#endif
