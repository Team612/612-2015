#include "Drive.h"

Drive::Drive(float inMagnitude, float inDirection, float inRotation)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	//Requires(MecanumDrivetrain);
	magnitude = inMagnitude;
	direction = inDirection;
	rotation = inRotation;
}

// Called just before this Command runs the first time
void Drive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	MecanumDrivetrain::move(magnitude, direction, rotation);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{

}
