#include "ElevatorMoveToPosition.h"

ElevatorMoveToPosition::ElevatorMoveToPosition(GamePad* joy)
{
	Requires(elevator);
	joystick = joy;
	isManualEngaged = true;
	wasManualEngaged = true;
	preset = getPresetHeight();
}

// Called just before this Command runs the first time
void ElevatorMoveToPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ElevatorMoveToPosition::Execute()
{
	elevator->move(joystick->GetRightYSmooth());
	//printf("Elevator Height= %f\n", elevator->getElevatorHeight());
}

void ElevatorMoveToPosition::moveToHeight(int inchesUp)
{
	int
}

int ElevatorMoveToPosition::getPresetHeight()
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
