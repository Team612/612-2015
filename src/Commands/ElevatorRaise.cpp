#include "ElevatorRaise.h"

ElevatorRaise::ElevatorRaise()
{
	Requires(elevator);
}

// Called just before this Command runs the first time
void ElevatorRaise::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ElevatorRaise::Execute()
{
	elevator -> move(0.8);
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorRaise::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ElevatorRaise::End()
{
	elevator -> stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorRaise::Interrupted()
{
	elevator -> stop();
}
