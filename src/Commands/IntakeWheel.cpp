#include "IntakeWheel.h"

IntakeWheel::IntakeWheel(GamePad* joystick)
{
	//Requires(elevator);
	//Requires(drivetrain);
	joyObj = joystick;
	rightFeedWheel = new CANTalon(RIGHT_FEED_MOTOR);
	leftFeedWheel = new CANTalon(LEFT_FEED_MOTOR);
}

// Called just before this Command runs the first time
void IntakeWheel::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeWheel::Execute()
{
/*if(joyObj->GetButtonStateLB() || joyObj->GetButtonStateRB())
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
	wasPressed = isPressed;
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
}*/
	rightFeedWheel->Set(joyObj->GetLeftYSmooth());
	leftFeedWheel->Set(joyObj->GetLeftYSmooth());
	//printf("Y input %f\n", joyObj->GetLeftYSmooth());
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeWheel::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeWheel::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeWheel::Interrupted()
{

}
