#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/Move.h"
#include "CommandBase.h"
#include "Robot.h"
#include "RobotMap.h"

void Robot::RobotInit()
{
	CommandBase::init();
	lw = LiveWindow::GetInstance();
	joy = new Joystick(0);

	drivetrain = new Drivetrain();
	//Remember to do this, and it must come after the drivetrain constructor call
}

void Robot::DisabledInit()
{

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
	//Get the values from the joystick
	float x = joy->GetRawAxis(LEFT_X);
	float y = joy->GetRawAxis(LEFT_Y);
	float rotation = joy->GetRawAxis(RIGHT_X);

	drivetrain->move(x,y,rotation);
}

void Robot::TestInit()
{

}

void Robot::TestPeriodic()
{
//	lw->Run();

}

float Robot::getValues(int axis)
{
	float val = joy->GetRawAxis(axis);
	if (axis < TOLORANCE && axis > -TOLORANCE)
	{
		return 0.0f;
	}
	else
	{
		if (axis == 0 || axis == 4)
		{
			return -val*THROTTLE;
		}
		else
		{
			return val*THROTTLE;
		}
	}
}

void Robot::MecDrive(float x, float y, float rotation)
{
}

START_ROBOT_CLASS(Robot);

