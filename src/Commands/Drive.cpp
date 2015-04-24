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
		//printf("DriveExec0\n %f", joyObj->GetLeftYSmooth());
		if(joyObj->isFStick)
		{
			*power = ((joyObj->GetRightYSmooth()*(-0.7f))+1)/2;
			if(*power < 0.2f)
			{
				*power = 0.2f;
			}
			drivetrain->move(((*power)*joyObj->GetLeftXRaw()) * 1.5f, (-1.0f)*(*power)*(joyObj->GetLeftYRaw()), (-*power)*joyObj->GetRightXSmooth());
		}
		else
		{
			if (joyObj->GetButtonStateRB())
				*power = MOTOR_HIGH;
			else if (joyObj->GetButtonStateLB())
				*power = MOTOR_LOW;
			drivetrain->move((*power)*joyObj->GetLeftXSmooth(), (-1.0f)*(*power)*(joyObj->GetLeftYSmooth()), (-*power)*joyObj->GetRightXSmooth());
		}
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
