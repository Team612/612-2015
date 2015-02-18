#include "RedLEDOn.h"

RedLEDOn::RedLEDOn() : CommandBase("RightLEDOn")

{
	Requires(led);
}

// Called just before this Command runs the first time
void RedLEDOn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RedLEDOn::Execute()
{
	led->setGreen(false);
	led->setRed(true);
}

// Make this return true when this Command no longer needs to run execute()
bool RedLEDOn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RedLEDOn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RedLEDOn::Interrupted()
{

}
