#include "ElevatorMoveToPosition.h"

ElevatorMoveToPosition::ElevatorMoveToPosition(GamePad* joy, float presetSpeed)
{
	Requires(elevator);
	joystick = joy;
	isManualEngaged = true;
	wasManualEngaged = true;
	isLB = false;
	wasLB = false;
	isRB = false;
	wasRB = false;
	isDynamic = true;
	speed = presetSpeed;
	preset = getPreset();
}
ElevatorMoveToPosition::ElevatorMoveToPosition(int presetMove, float presetSpeed)
{
	Requires(elevator);
	joystick = NULL;
	isManualEngaged = true;
	wasManualEngaged = true;
	isLB = false;
	wasLB = false;
	isRB = false;
	wasRB = false;
	isDynamic = false;
	speed = presetSpeed;
	preset = presetMove;
}
// Called just before this Command runs the first time
void ElevatorMoveToPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ElevatorMoveToPosition::Execute()
{
	//printf("IS ELEVATORMOVETOPOSITION/n");
	if(isDynamic)
	{
		if(joystick->GetLeftYSmooth() != 0.0f)
		{
			isManualEngaged = true;
			//printf("IS ELEVATORMOVETOPOSITION MANUAL SET\n");
		}
		else if(joystick->GetButtonStateLB() || joystick->GetButtonStateRB())
		{
			isManualEngaged = false;
			//printf("BWAHAHAAHAH\n");
			//printf("IS ELEVATORMOVETOPOSITION MANUAL UN SET\n");
		}
		if(isManualEngaged)
		{
			elevator->move(-joystick->GetLeftYSmooth());
			//printf("IS ELEVATORMOVETOPOSITION MANUAL\n");
		}
		else
		{
			//printf("Elevpreset code\n");
			if(!isManualEngaged && wasManualEngaged)
			{
				preset = getPreset();
				//printf("getPreset()=%i\n", getPreset());

			}
			if(joystick->GetButtonStateLB())
			{
				isLB = true;
				if(isLB && !wasLB)
				{
					preset--;
				}
			}
			if(joystick->GetButtonStateRB())
			{
				isRB = true;
				if(isRB && !wasRB)
				{
					preset++;
				}
			}
			if(preset < 0)
			{
				preset = 0;
			}
			if(preset > 6)
			{
				preset = 6;
			}
			//printf("preset=%i\n", preset);
			moveToHeight(preset * 12.1f);
		}
		wasManualEngaged = isManualEngaged;
		wasLB = isLB;
		wasRB = isRB;
		//printf("IS ELEVATORMOVETOPOSITION END \n");
	}
	else
	{
		moveToHeight((preset * 12.1f) + 2);
	}
	elevator->getElevatorHeight();
	//printf("Elevator Height= %f\n", elevator->getElevatorHeight());
}

void ElevatorMoveToPosition::moveToHeight(float inchesUp)
{
	//printf("getElevatorHeight()=%f\n", elevator->getElevatorHeight());
	//printf("inchesUp%f\n", inchesUp);
	if(elevator->getElevatorHeight() < inchesUp - HEIGHT_TOLERANCE)
	{
		elevator->move(speed);
	}
	else if(elevator->getElevatorHeight() > inchesUp + HEIGHT_TOLERANCE)
	{
		elevator->move(-speed);
	}
	else
	{
		elevator->stop();
	}
	count++;
}

int ElevatorMoveToPosition::getPreset()
{
	return (elevator->getElevatorHeight() / 12.1f);
}
// Make this return true when this Command no longer needs to run execute()
bool ElevatorMoveToPosition::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ElevatorMoveToPosition::End()
{
	elevator->stop(); //make sure elevator doesn't go whacko
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorMoveToPosition::Interrupted()
{
	elevator->stop(); //make sure elevator doesn't go whacko
}
