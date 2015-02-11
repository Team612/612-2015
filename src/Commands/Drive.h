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
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float targetX;
	float targetY;
	float targetRotation;
};

#endif
