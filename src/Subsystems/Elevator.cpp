#include "Elevator.h"

Elevator::Elevator() :
	Subsystem("Elevator")
{
	talon = new Talon(ELEVATOR_MOTOR); //constants in src/RobotMap.h
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

	//If the sensors give any input then the elevator can't be moved more that way, so don't move
	if (topInput || bottomInput)
	{
		talon->Set(0); //sets speed to 0
	}
	else
	{
		talon->Set(magnitude); //Sets speed to inputted speed
	}
	static int count = 0;
	if (count % 60 == 0)
	{
		printf("Elevator motor moved! Speed = %f", magnitude));
	}
}

void Elevator::stop()
{
	//Sets motor speed to nothing
	talon->Set(0);
	printf("Stop elevator motor");
}

Encoder* Elevator::getEncoder()
{
	return encoder;
}

