#include "ElevatorMoveToPosition.h"

ElevatorMoveToPosition::ElevatorMoveToPosition(uint32_t inPosition)
{
	Requires(elevator);
	targetPosition = inPosition;
	targetSpins = targetPosition * INTERVAL;
}

// Called just before this Command runs the first time
void ElevatorMoveToPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ElevatorMoveToPosition::Execute()
{
	int spins = elevator->getEncoder()->Get();

	if (spins > targetSpins)
	{
		elevator->move(-0.8);
	}
	else if (spins < targetSpins)
	{
		elevator->move(0.8);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorMoveToPosition::IsFinished()
{
	int spins = elevator->getEncoder()->Get();

	bool isAtPos = targetSpins == spins;
	return isAtPos;
}

// Called once after isFinished returns true
void ElevatorMoveToPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorMoveToPosition::Interrupted()
{

}
