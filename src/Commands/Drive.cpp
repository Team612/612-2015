#include "CommandBase.h"
#include "Drive.h"

Drive::Drive(float x, float y, float rotation)
{
	targetX = x;
	targetY = y;
	targetRotation = rotation;
	Requires(drivetrain);
}
// Called just before this Command runs the first time
void Drive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	drivetrain->move(targetX, targetY, targetRotation);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{
	drivetrain->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{
	drivetrain->stop();
}
