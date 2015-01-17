#include "MecanumDrivetrain.h"
#include "../RobotMap.h"
#include <Talon.h>

MecanumDrivetrain::MecanumDrivetrain(uint8_t talonmod1, uint32_t talonchannel1,
		                             uint8_t talonmod2, uint32_t talonchannel2,
		                             uint8_t talonmod3, uint32_t talonchannel3,
		                             uint8_t talonmod4, uint32_t talonchannel4):
		Subsystem("MecanumDrivetrain"),
		RobotDrive(new Talon(talonmod1, talonchannel1),
				   new Talon(talonmod2, talonchannel2),
				   new Talon(talonmod3, talonchannel3),
				   new Talon(talonmod4, talonchannel4))
{
	//import trackball or something? idk.
}

void MecanumDrivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.

	//SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void MecanumDrivetrain::moveForwards(float rotationf)
{
	MecanumDrive_Polar(0.5, 90, rotationf);
}
void MecanumDrivetrain::moveBackwards(float rotationb)
{

}
void MecanumDrivetrain::moveLeft(float rotationl)
{

}
void MecanumDrivetrain::moveRight(float rotationr)
{

}
