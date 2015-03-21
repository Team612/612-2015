#include "ElevatorMoveToPosition.h"

ElevatorMoveToPosition::ElevatorMoveToPosition()
{
	Requires(elevator);
}

// Called just before this Command runs the first time
void ElevatorMoveToPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ElevatorMoveToPosition::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorMoveToPosition::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ElevatorMoveToPosition::End()
{
	elevator->stop(); //make sure elevator doesn't go whacko
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorMoveToPosition::Interrupted()
{
	elevator->stop(); //make sure elevator doesn't go whacko
}
