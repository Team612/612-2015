#include "Infrared612.h"
#include "../RobotMap.h"

Infrared612::Infrared612() :
		Subsystem("Infrared")
{
	infrared612 = new AnalogInput(3); //get actual ports. Preferably in RobotMap.h
}

void Infrared612::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
