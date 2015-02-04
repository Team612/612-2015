#ifndef SmoothJoystick_H
#define SmoothJoystick_H

#include "WPILib.h"
#include <Joystick.h>
#include "OI.h"

class SmoothJoystick: public Joystick
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	SmoothJoystick(int port); //Constructor
	//void InitDefaultCommand();
	float GetValue(int axis);

	/*
	 * GetValue() can be used to get value of an joystick (Run InitJoystick() first).
	 * X axis = 0, y axis = 1
	 * left hand = 0, right hand = 1
	 */

	void autoInvert();
};

#endif
