#include "LeftLEDOn.h"

LeftLEDOn::LeftLEDOn()
{
	LeftLEDGreen = new DigitalOutput(L_ELEVATOR_LED_GREEN);
	LeftLEDRed = new DigitalOutput(L_ELEVATOR_LED_RED);
}

// Called just before this Command runs the first time
void LeftLEDOn::Initialize()
{
	LeftLEDGreen->Set(1);
	LeftLEDRed->Set(1);

}

// Called repeatedly when this Command is scheduled to run
void LeftLEDOn::Execute()
{
	static int c = 0;
	if (c % 60 == 0) //prints every second
	{
		printf("LEDs on execution called\n");
	}
	c++;
}

// Make this return true when this Command no longer needs to run execute()
bool LeftLEDOn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LeftLEDOn::End()
{
	LeftLEDGreen->Set(0);
	LeftLEDRed->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LeftLEDOn::Interrupted()
{
	LeftLEDGreen->Set(0);
	LeftLEDRed->Set(0);
}
