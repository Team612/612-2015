#include "Elevator.h"
#include "../RobotMap.h"

Elevator::Elevator(uint32_t channel) :
		Subsystem("Elevator")
{
	controller = new Talon(channel);
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Elevator::move(float magnitude)
{
	controller -> Set(0.1);
}

void Elevator::stop()
{

}



// Put methods for controlling this subsystem
// here. Call these from Commands.


