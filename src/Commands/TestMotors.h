#ifndef TestMotors_H
#define TestMotors_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/MecanumDrivetrain.h"
#include <Timer.h>
#include "RobotMap.h"

class TestMotors: public CommandBase
{
private:
	Timer* testMotorTimer;
	//MecanumDrivetrain* drive;
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


