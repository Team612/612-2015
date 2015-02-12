#ifndef DRIVE_H
#define DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include <Timer.h>
#include "RobotMap.h"

class Drive: public CommandBase
{
public:
	Drive(float x, float y, float rotation);
	Drive(Joystick* joystick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	typedef enum DriveMode {MANUAL, JOYSTICK};

	DriveMode mode;

	float targetX;
	float targetY;
	float targetRotation;

	Joystick* joystick;

};

#endif
