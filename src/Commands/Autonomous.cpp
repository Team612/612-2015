#include "Autonomous.h"

Autonomous::Autonomous(float autoDist, float autoSpeed, AutoMode autoMode)
{
	Requires(drivetrain);
	autodist = autoDist;
	autospeed = (1.0f) * autoSpeed;
	automode = autoMode;
	isfinished = false;
}

Autonomous::~Autonomous()
{

}

// Called just before this Command runs the first time
void Autonomous::Initialize()
{
	drivetrain->resetEncoders();
	drivetrain->stop();
}

// Called repeatedly when this Command is scheduled to run
void Autonomous::Execute()
{
	if(automode == NO_AUTO)
	{
		drivetrain->stop();
	}
	else if(automode == FORWARD_PUSH)
	{
		printf("Autonomous(FORWARD_PUSH).cpp %f \n", autospeed);
		Drive* forward = new Drive(0.0f, autospeed, 0.0f);
		forward->Start();
		if(autodist<=abs(drivetrain->getDistance(Drivetrain::ALL_AVERAGE)))
		{
			isfinished = true;
			printf("Auto finished with autodist %f", autodist);
		}
	}
	else if(automode == SIDEWAYS_PUSH)
	{
		drivetrain->move(autospeed, 0.0f, 0.0f);
		if(autodist<=(abs(drivetrain->getDistance(Drivetrain::MAJOR_DIAGONAL))+abs(drivetrain->getDistance(Drivetrain::MINOR_DIAGONAL))))
		{
			isfinished = true;
		}
	}
	else if(automode == ONE_BIN_PUSHSTACK)
	{
		isfinished = true;
		//TODO Actually code anything in THREE_TOTE auto mode. Need testing. Yes. Definitely.
	}
	else if(automode == ONE_BIN_CARRYSTACK)
	{
		isfinished = true;
		//TODO Actually code anything in THREE_TOTE auto mode. Need testing. Yes. Definitely.
	}
	else if(automode == TWO_BIN_PUSHSTACK)
	{
		isfinished = true;
		//TODO Actually code anything in THREE_TOTE auto mode. Need testing. Yes. Definitely.
	}
	else if(automode == TWO_BIN_CARRYSTACK)
	{
		isfinished = true;
		//TODO Actually code anything in THREE_TOTE auto mode. Need testing. Yes. Definitely.
	}
	else if(automode == THREE_BIN_PUSHSTACK)
	{
		isfinished = true;
		//TODO Actually code anything in THREE_TOTE auto mode. Need testing. Yes. Definitely.
	}
	else if(automode == THREE_BIN_CARRYSTACK)
	{
		isfinished = true;
		//TODO Actually code anything in THREE_TOTE auto mode. Need testing. Yes. Definitely.
	}
	else
	{
		isfinished = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Autonomous::IsFinished()
{
	return isfinished;
}

// Called once after isFinished returns true
void Autonomous::End()
{
	drivetrain->resetEncoders();
	drivetrain->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous::Interrupted()
{
	drivetrain->resetEncoders();
	drivetrain->stop();
}
