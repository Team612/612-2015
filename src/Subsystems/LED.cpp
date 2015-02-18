#include "LED.h"
#include "../RobotMap.h"

LED::LED() :
		Subsystem("ExampleSubsystem")
{
	LeftLEDGreen = new DigitalOutput(L_ELEVATOR_LED_GREEN);
	LeftLEDRed = new DigitalOutput(L_ELEVATOR_LED_RED);
	RightLEDGreen = new DigitalOutput(L_ELEVATOR_LED_GREEN);
	RightLEDRed = new DigitalOutput(L_ELEVATOR_LED_RED);
}

void LED::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void LED::setGreen(bool on)
{
	if (on)
	{
		RightLEDGreen->Set(1);
		LeftLEDGreen->Set(1);
	}

	else

	{
		RightLEDGreen->Set(0);
		LeftLEDGreen->Set(0);
	}
}

void LED::setRed(bool on)
{
	if (on)
	{
		RightLEDRed->Set(1);
		LeftLEDRed->Set(1);
	}

	else

	{
		RightLEDRed->Set(0);
		LeftLEDRed->Set(0);
	}
}




