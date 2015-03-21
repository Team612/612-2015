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
	feedState = 0;
	isPressed = false;
	wasPressed = false;
}

Drive::Drive(GamePad* joystick)
{
	Requires(drivetrain);
	mode = JOYSTICK;
	joyObj = joystick;
	targetX = 0;
	targetY = 0;
	targetRotation = 0;
	feedState = 0;
	isPressed = false;
	wasPressed = false;
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
		if(joyObj->GetButtonStateRB() || joyObj->GetButtonStateRB())
		{
			isPressed = true;
		}
		if(!wasPressed && isPressed)
		{
			if (joyObj->GetButtonStateRB())
			{
				if(feedState == 2)
				{
					feedState = 1;
				}
				else
				{
					feedState = 2;
				}
			}
			else if (joyObj->GetButtonStateLB())
			{
				if(feedState == 0)
				{
					feedState = 1;
				}
				else
				{
					feedState = 2;
				}
			}
		}
		else
		{
			isPressed = wasPressed;
		}
		if(feedState == 0)
		{
			drivetrain->SetLeftFeedWheel(1.0f);
			drivetrain->SetRightFeedWheel(1.0f);
		}
		else if(feedState == 2)
		{
			drivetrain->SetRightFeedWheel(-1.0f);
			drivetrain->SetLeftFeedWheel(-1.0f);
		}
		else
		{
			drivetrain->SetRightFeedWheel(0);
			drivetrain->SetLeftFeedWheel(0);
		}
		//printf("DriveExec0\n %f", joyObj->GetLeftYSmooth());
		//if()
		*power = -joyObj->GetRightYSmooth();
		 float powar = -joyObj->GetRightYSmooth();

		drivetrain->move((*power)*joyObj->GetLeftXSmooth(), (*power)*joyObj->GetLeftYSmooth(), (-*power)*joyObj->GetRightXSmooth());
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
