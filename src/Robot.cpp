#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/Move.h"
#include "CommandBase.h"

void Robot::RobotInit()
{
	CommandBase::init();
	lw = LiveWindow::GetInstance();
}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{

}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	printf("Teleop Initialized");
}

void Robot::TeleopPeriodic()
{
	printf("Teleop Periodic start");
	//moveCommand->Start();
}

void Robot::TestInit()
{

}

void Robot::TestPeriodic()
{
//	lw->Run();

}

START_ROBOT_CLASS(Robot);

