#include "ElevatorMove.h"

ElevatorMove::ElevatorMove(GamePad* joy)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(elevator);
	joystick = joy;
}

// Called just before this Command runs the first time
void ElevatorMove::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ElevatorMove::Execute()
{
	elevator->move(joystick->GetRightYSmooth());
	printf("Moving elevator\n");
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorMove::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ElevatorMove::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorMove::Interrupted()
{

}
