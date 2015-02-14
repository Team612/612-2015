#include "CommandBase.h"
#include "Drive.h"

Drive::Drive(Joystick* stick)
{
	// Use Requirevas() here to declare subsystem dependencies
	// eg. Requires(chassis)
	joy = stick;
	Requires(drivetrain);
}
// Called just before this Command runs the first time
void Drive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	drivetrain->move(joy->GetRawAxis(LEFT_X),joy->GetRawAxis(LEFT_Y),joy->GetRawAxis(RIGHT_X));
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{
	drivetrain->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{
	drivetrain->stop();
}
