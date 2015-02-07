#include "Elevator.h"

Elevator::Elevator() :
	Subsystem("Elevator")
{
	talon = new Talon(ELEVATOR_MOTOR);
	topSwitch = new DigitalInput(ELEVATOR_TOP_SWITCH);
	bottomSwitch = new DigitalInput(ELEVATOR_BOTTOM_SWITCH);
	encoder = new Encoder(ELEVATOR_ENCODER_A, ELEVATOR_ENCODER_B);
	left = new AnalogInput(LEFT_IR);
	right = new AnalogInput(RIGHT_IR);
	sense = IR;
}

Elevator::~Elevator()
{
	delete talon;
}

void Elevator::InitDefaultCommand()
{
	//SetDefaultCommand(new ElevatorUp());
}

void Elevator::move(float magnitude)
{
	//Checks the sensors to see if the elevator is at the top or the bottom
	bool topInput = topSwitch->Get();
	bool bottomInput = bottomSwitch->Get();

	//If the sensors give any input then the motors are set to a speed of 0
	if (topInput || bottomInput)
	{
		talon->Set(0);
	}
	else
	{
		talon->Set(magnitude);
	}
}

void Elevator::stop()
{
	//Sets motor speed to nothing
	talon->Set(0);
}

Encoder* Elevator::getEncoder()
{
	return encoder;
}

bool Elevator::getLeftAlignment()
{
	val = left->GetVoltage();
	val = voltageToDistance(val);
	
	if (val >= (distance - BUFFER) && val <= (distance + BUFFER)) //Distance to ground +/- 2 inches TODO
	{
		return false;
	}
	else
	{
		return true;
	}
	
}
bool Elevator::getRightAlignment()
{
	val = right->GetVoltage();
	val = voltageToDistance(val);
	
	if (val >= (distance - BUFFER) && val <= (distance + BUFFER)) //Distance to ground +/- 2 inches TODO
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

float Elevator::voltageToDistance(float val)
{
	return ((4187.8/val)**1.1060)/2.54; //make sure this is right, make sure it returns INCHES
}

float Elevator::getElevatorHeight()
{
	return 1.0f; //TODO
}
