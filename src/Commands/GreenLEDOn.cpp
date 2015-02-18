#include "GreenLEDOn.h"

GreenLEDOn::GreenLEDOn() : CommandBase("GreenLEDOn")
{
	Requires(led);
}

// Called just before this Command runs the first time
void GreenLEDOn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GreenLEDOn::Execute()
{
	led->setRed(false);
	led->setGreen(true);
}

// Make this return true when this Command no longer needs to run execute()
bool GreenLEDOn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GreenLEDOn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GreenLEDOn::Interrupted()
{

}
