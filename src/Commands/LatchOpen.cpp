#include "LatchOpen.h"

LatchOpen::LatchOpen()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(elevator);
}

// Called just before this Command runs the first time
void LatchOpen::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LatchOpen::Execute()
{
	elevator->latchSolOpen();
}

// Make this return true when this Command no longer needs to run execute()
bool LatchOpen::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LatchOpen::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LatchOpen::Interrupted()
{
	elevator->latchSolClose();
}
