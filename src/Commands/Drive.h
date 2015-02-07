#ifndef DRIVE_H
#define DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
<<<<<<< HEAD
=======
#include "../Subsystems/DriveTrain.h"
>>>>>>> 2ab036a4697cde7d0c943de9a978246519b3694a
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
