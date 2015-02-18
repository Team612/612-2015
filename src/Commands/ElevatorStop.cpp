#include "ElevatorStop.h"

ElevatorStop::ElevatorStop()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(elevator);
}

// Called just before this Command runs the first time
void ElevatorStop::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ElevatorStop::Execute()
{
	elevator->stop();
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorStop::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ElevatorStop::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorStop::Interrupted()
{

}
