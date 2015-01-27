#include "Drive.h"


Drive::Drive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires(drivetrain);

}

// Called just before this Command runs the first time
void Drive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute(float x, float y, float rotation)
{
	drivetrain->move(x,y,rotation);
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

// Called when another comma
// Called repeatedly when this Cond which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{
	drivetrain->stop();
}
