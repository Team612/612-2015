#include "RightLEDOn.h"

RightLEDOn::RightLEDOn()
{
	RightLEDGreen = new DigitalOutput(L_ELEVATOR_LED_GREEN);
	RightLEDRed = new DigitalOutput(L_ELEVATOR_LED_RED);
}

// Called just before this Command runs the first time
void RightLEDOn::Initialize()
{
	RightLEDGreen->Set(1);
	RightLEDRed->Set(1);

}

// Called repeatedly when this Command is scheduled to run
void RightLEDOn::Execute()
{
	static int c = 0;
	if (c % 60 == 0) //prints every second
	{
		printf("LEDs on execution called\n");
	}
	c++;
}

// Make this return true when this Command no longer needs to run execute()
bool RightLEDOn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RightLEDOn::End()
{
	RightLEDGreen->Set(0);
	RightLEDRed->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RightLEDOn::Interrupted()
{
	RightLEDGreen->Set(0);
	RightLEDRed->Set(0);
}
