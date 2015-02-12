#include "Elevator.h"

Elevator::Elevator() :
	Subsystem("Elevator")
{
	talon = new CANTalon(ELEVATOR_MOTOR_1);
	talon2 = new CANTalon(ELEVATOR_MOTOR_2);
	topSwitch = new DigitalInput(ELEVATOR_TOP_SWITCH);
	bottomSwitch = new DigitalInput(ELEVATOR_BOTTOM_SWITCH);
	encoder = new Encoder(ELEVATOR_ENCODER_A, ELEVATOR_ENCODER_B);
}

Elevator::~Elevator()
{
	delete talon;
	delete talon2;
}

void Elevator::InitDefaultCommand()
{
	//SetDefaultCommand(new ElevatorUp());
}

void Elevator::move(float magnitude)
{
	//Checks the sensors to see if the elevator is at the top or the bottom
	//bool topInput = topSwitch->Get();
	//bool bottomInput = bottomSwitch->Get();

	//If the sensors give any input then the motors are set to a speed of 0
	//if (topInput || bottomInput)
	//{
	//	talon->Set(0);
	//	talon2->Set(0);
	//}
	//else
	//{
		talon->Set(magnitude);
		talon2->Set(magnitude);
	//}
}

void Elevator::stop()
{
	//Sets motor speed to nothing
	talon->Set(0);
	talon2->Set(0);
}

Encoder* Elevator::getEncoder()
{
	return encoder;
}

