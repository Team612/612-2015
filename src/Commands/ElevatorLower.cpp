#include "ElevatorLower.h"

ElevatorLower::ElevatorLower()
{
	Requires(elevator);
}

// Called just before this Command runs the first time
void ElevatorLower::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ElevatorLower::Execute()
{
	//Using -0.8 as a temporary value
	elevator -> move(-0.8);
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorLower::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ElevatorLower::End()
{
	elevator -> stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorLower::Interrupted()
{
	elevator -> stop();
}
