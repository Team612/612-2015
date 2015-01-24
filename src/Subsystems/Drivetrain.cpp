#include "Drivetrain.h"
#include "../RobotMap.h"

Drivetrain::Drivetrain(uint32_t talonfl, uint32_t talonbl, uint32_t talonfr, uint32_t talonbr):
		Subsystem("Drivetrain"),
		RobotDrive(talonfl, talonbl, talonfr, talonbr)
{

}

void Drivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::move(float magnitude, float direction, float rotation)
{
	MecanumDrive_Polar(magnitude, direction, rotation);
}

void Drivetrain::stahp()
{
	MecanumDrive_Polar(0.0f, 0.0f, 0.0f);
}
