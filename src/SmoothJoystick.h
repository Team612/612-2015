/*
 * SmoothJoystick.h
 *
 *  Created on: Jan 30, 2015
 *      Author: zachary
 */

#ifndef SRC_SMOOTHJOYSTICK_H_
#define SRC_SMOOTHJOYSTICK_H_

#include <Joystick.h>
#include "RobotMap.h"

class SmoothJoystick: public Joystick
{
public:
	SmoothJoystick(int port);
	virtual ~SmoothJoystick();
	float GetModValue(int axis);
};

#endif /* SRC_SMOOTHJOYSTICK_H_ */
