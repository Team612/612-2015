#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/Move.h"
#include "CommandBase.h"
#include <cstdio>

class Robot: public IterativeRobot
{
private:
	LiveWindow* lw;
	Move* moveCommand = new Move();

	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
		moveCommand->End();
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		printf("Teleop Initialized");
	}

	void TeleopPeriodic()
	{
		printf("Teleop Periodic start");
		moveCommand->Execute();
	}

	void TestPeriodic()
	{
		lw->Run();

	}
};

START_ROBOT_CLASS(Robot);

