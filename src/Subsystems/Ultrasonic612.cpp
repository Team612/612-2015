#include <Subsystems/Ultrasonic612.h>
#include "../RobotMap.h"

Ultrasonic612::Ultrasonic612() :
		Subsystem("Ultrasonic")
{
	ultraDI_1 = (unsigned)1;
	ultraDO_1 = (unsigned)1;
	ultraDI_2 = (unsigned)2;
	ultraDO_2 = (unsigned)2;

	ultrasonicL = new Ultrasonic(ultraDI_1, ultraDO_1);
	ultrasonicR = new Ultrasonic(ultraDI_2, ultraDO_2);
}

void Ultrasonic612::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

double Ultrasonic612::measureL()
{
	ultrasonicL->Ping();
	return ultrasonicL->GetRangeInches();
}

double Ultrasonic612::measureR()
{
	ultrasonicR->Ping();
	return ultrasonicR->GetRangeInches();
}
