#include "Elevator.h"

Elevator::Elevator() :
	Subsystem("Elevator")
{
	talon = new TalonSRX(ELEVATOR_MOTOR);
	topSwitch = new DigitalInput(ELEVATOR_TOP_SWITCH);
	bottomSwitch = new DigitalInput(ELEVATOR_BOTTOM_SWITCH);
	encoder = new Encoder(ELEVATOR_ENCODER_A, ELEVATOR_ENCODER_B);
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
		talon->Set(0.0f);
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

void Elevator::firstSolOpen()
{
	firstsolenoid->Set(DoubleSolenoid::Value::kForward);
}

void Elevator::firstSolClose()
{
	firstsolenoid->Set(DoubleSolenoid::Value::kOff);
}

void Elevator::secondSolOpen()
{
	secondsolenoid->Set(DoubleSolenoid::Value::kForward);
}

void Elevator::secondSolClose()
{
	secondsolenoid->Set(DoubleSolenoid::Value::kOff);
}
