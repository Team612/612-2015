#include <Subsystems/Elevator.h>

Elevator::Elevator(uint32_t channel) :
	Subsystem("Elevator")
{
	talon = new Talon(channel);
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
	/*
	 - One class for commands
	 - Requires argument for direction (Enum?)
	 - Requires argument for amount (Spins)
	 - Other command that sets the elevator to presets
	 - Add implementation for time in case there is no encoder
	 */

	//Move the elevator up or down
	talon -> Set(magnitude);
}

void Elevator::stop()
{
	move(0);
}

