#include "CommandBase.h"
#include "Drive.h"

Drive::Drive(float x, float y, float rotation)
{
	Requires(drivetrain);
	mode = MANUAL;
	targetX = x;
	targetY = y;
	targetRotation = rotation;
}

Drive::Drive(Joystick* joy)
{
	Requires(drivetrain);
	mode = JOYSTICK;
	joystick = joy;
	targetX = 0;
	targetY = 0;
	targetRotation = 0;
}

// Called just before this Command runs the first time
void Drive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	if (mode == JOYSTICK)
	{
		targetX = joystick->GetRawAxis(LEFT_X);
		targetY = joystick->GetRawAxis(LEFT_Y);
		targetRotation = joystick->GetRawAxis(RIGHT_X);
	}

	drivetrain->move(targetX, targetY, targetRotation);
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
