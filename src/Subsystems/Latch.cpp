#include "Latch.h"
#include "../RobotMap.h"

Latch::Latch() :
	Subsystem("Latch")
{
    // Initialize the variable you made in Latch.h
	//solenoid = new Solenoid(SOLENOID_LATCH);
	//relay = new Relay(RELAY_LATCH);
}

void Latch::Open()
{
    // Using the WPILIB documentation, you would use the variable
    // and one of its methods to enable the latch.
	solenoid->Set(true);
	relay->Set(Relay::Value::kForward);
}

void Latch::Close()
{
    // Same as the previous, except you disable the latch.
	solenoid->Set(false);
	relay->Set(Relay::Value::kReverse);
}

