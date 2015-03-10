#include "CommandBase.h"
#include "AutoAlign.h"

AutoAlign::AutoAlign()
{
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void AutoAlign::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoAlign::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutoAlign::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoAlign::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoAlign::Interrupted()
{

}
