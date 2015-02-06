#ifndef DRIVE_H
#define DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include <Timer.h>
#include "RobotMap.h"

class Drive: public CommandBase
{
public:
	Drive();
	void Initialize();
	void Execute(float inMagnitude, float inDirection, float inRotation);
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
