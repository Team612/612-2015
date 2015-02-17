#include "ElevatorUp.h"

ElevatorUp::ElevatorUp()
{
	Requires(elevator);
}

// Called just before this Command runs the first time
void ElevatorUp::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ElevatorUp::Execute()
{
	elevator->move(ELEV_SPEED_DOUBLE);
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorUp::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ElevatorUp::End()
{
	elevator->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorUp::Interrupted()
{
	elevator->stop();
}
