#include "LatchClose.h"

LatchClose::LatchClose()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(elevator);
}

// Called just before this Command runs the first time
void LatchClose::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LatchClose::Execute()
{
	elevator->latchSolClose();
}

// Make this return true when this Command no longer needs to run execute()
bool LatchClose::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LatchClose::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LatchClose::Interrupted()
{
	elevator->latchSolClose();
}
