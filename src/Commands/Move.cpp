#include "Move.h"

Move::Move()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrain);
	driverJoy = new Joystick(1);
}

// Called just before this Command runs the first time
void Move::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Move::Execute()
{
	drivetrain->move(driverJoy->GetY(), driverJoy->GetX(), driverJoy->GetRawAxis(4));
}

// Make this return true when this Command no longer needs to run execute()
bool Move::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Move::End()
{
	drivetrain->stahp();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Move::Interrupted()
{

}
