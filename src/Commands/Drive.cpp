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

Drive::Drive(Joystick* joystick)
{
	Requires(drivetrain);
	mode = JOYSTICK;
	joyObj = joystick;
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
		targetX = joyObj->GetRawAxis(LEFT_X);
		targetY = joyObj->GetRawAxis(LEFT_Y);
		targetRotation = joyObj->GetRawAxis(RIGHT_X);
		drivetrain->move(targetX, targetY, targetRotation);

		SmartDashboard::PutNumber("Front left Talon value", drivetrain->fl612Talon->Get());
		SmartDashboard::PutNumber("Front right Talon value", drivetrain->fr612Talon->Get());
		SmartDashboard::PutNumber("Back left Talon value", drivetrain->bl612Talon->Get());
		SmartDashboard::PutNumber("Back right Talon value", drivetrain->br612Talon->Get());
	}
	else
	{
		drivetrain->move(targetX, targetY, targetRotation);
	}
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
