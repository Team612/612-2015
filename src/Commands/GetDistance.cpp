#include "GetDistance.h"

GetDistance::GetDistance()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(ultrasonic612);
}

// Called just before this Command runs the first time
void GetDistance::Initialize()
{
	GetDistance::isGDDone = false;
}

// Called repeatedly when this Command is scheduled to run
void GetDistance::Execute()
{
	SmartDashboard::PutNumber("Current left measurement", ultrasonic612->measureL());
	SmartDashboard::PutNumber("Current right measurement", ultrasonic612->measureR());
	GetDistance::isGDDone = true;
}

// Make this return true when this Command no longer needs to run execute()
bool GetDistance::IsFinished()
{
	return GetDistance::isGDDone;
}

// Called once after isFinished returns true
void GetDistance::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetDistance::Interrupted()
{

}
