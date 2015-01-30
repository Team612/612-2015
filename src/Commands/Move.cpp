#include "Move.h"

Move::Move(Robot* r, Joystick* j)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrain);
	robot = r;
	joystick = j;
}

Move::~Move()
{
	delete robot;
	delete joystick;
}

// Called just before this Command runs the first time
void Move::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Move::Execute()
{


}

// Make this return true when this Command no longer needs to run execute()
bool Move::IsFinished()
{
	return false; //should always be false
}

// Called once after isFinished returns true
void Move::End()
{
	drivetrain->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Move::Interrupted()
{
	drivetrain->stop();
}
