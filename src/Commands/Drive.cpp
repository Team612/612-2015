#include "CommandBase.h"
#include "Drive.h"

Drive::Drive(float x, float y, float rotation)
{
	Requires(drivetrain);
	mode = MANUAL;
	targetX = x;
	targetY = y;
	targetRotation = rotation;
	joyObj = NULL;
}

Drive::Drive(GamePad* joystick)
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
	//printf("DriveInit\n");
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	if (mode == JOYSTICK)
	{
		float* power = &drivetrain->motor_power;
		if (joyObj->GetRawButton(BUTTON_R2))
			*power = MOTOR_HIGH;
		else if (joyObj->GetRawButton(BUTTON_L2))
			*power = MOTOR_LOW;
		//printf("DriveExec0\n %f", joyObj->GetLeftYSmooth());
#ifndef GAMEPAD
		*power = joyObj->GetRawAxis(-SLIDER);
#endif
		drivetrain->move((*power)*joyObj->GetLeftXSmooth(), (-*power)*joyObj->GetLeftYSmooth(), (-*power)*joyObj->GetRightXSmooth());
		//printf("DriveExec1\n");
		SmartDashboard::PutNumber("Front left Talon value", drivetrain->fl->Get());
		SmartDashboard::PutNumber("Front right Talon value", drivetrain->fr->Get());
		SmartDashboard::PutNumber("Back left Talon value", drivetrain->rl->Get());
		SmartDashboard::PutNumber("Back right Talon value", drivetrain->rr->Get());
	}
	else
	{
		//printf("DriveExec2\n");
		drivetrain->move(targetX, targetY, targetRotation);
		//printf("DriveExec3\n");
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
