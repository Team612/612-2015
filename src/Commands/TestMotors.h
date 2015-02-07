#ifndef TestMotors_H
#define TestMotors_H

#include "../CommandBase.h"
#include "WPILib.h"
<<<<<<< HEAD
#include "../Subsystems/Drivetrain.h"
=======
#include "../Subsystems/DriveTrain.h"
>>>>>>> 2ab036a4697cde7d0c943de9a978246519b3694a
#include <Timer.h>
#include "RobotMap.h"

class TestMotors: public CommandBase
{
private:
	Timer* testMotorTimer;
	DriveTrain* drive;
	bool isTestDone;
public:
	TestMotors();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif


