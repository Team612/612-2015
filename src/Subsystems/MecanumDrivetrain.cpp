#include "MecanumDrivetrain.h"
#include "../RobotMap.h"
#include <Talon.h>

MecanumDrivetrain::MecanumDrivetrain(uint32_t talonchannel1,
		                             uint32_t talonchannel2,
		                             uint32_t talonchannel3,
		                             uint32_t talonchannel4):
		Subsystem("MecanumDrivetrain"),
		RobotDrive(new Talon(talonchannel1),
				   new Talon(talonchannel2),
				   new Talon(talonchannel3),
				   new Talon(talonchannel4))
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
void MecanumDrivetrain::move(float magnitude, float direction, float rotation)
{
	MecanumDrive_Polar(magnitude,direction,rotation);
}

void MecanumDrivetrain::moveForwards()
{
	MecanumDrive_Polar(0.5, 90.0, 0.0);
}
void MecanumDrivetrain::moveBackwards()
{
	MecanumDrive_Polar(0.5, 90.0, 0.0);
}
void MecanumDrivetrain::moveLeft()
{
	MecanumDrive_Polar(0.5, 90.0, 0.0);
}
void MecanumDrivetrain::moveRight()
{
	MecanumDrive_Polar(0.5, 90.0, 0.0);
}

void MecanumDrivetrain::moveForwards(float rotationf)
{
	MecanumDrive_Polar(0.5, 90.0, rotationf);
}
void MecanumDrivetrain::moveBackwards(float rotationb)
{
	MecanumDrive_Polar(0.5, 270.0, rotationb);
}
void MecanumDrivetrain::moveLeft(float rotationl)
{
	MecanumDrive_Polar(0.5, 180, rotationl);
}
void MecanumDrivetrain::moveRight(float rotationr)
{
	MecanumDrive_Polar(0.5, 0, rotationr);
}

void MecanumDrivetrain::moveForwards(float directionf, float rotationf)
{
	MecanumDrive_Polar(0.5, directionf, rotationf);
}
void MecanumDrivetrain::moveBackwards(float directionb, float rotationb)
{
	MecanumDrive_Polar(0.5, directionb, rotationb);
}
void MecanumDrivetrain::moveLeft(float directionl, float rotationl)
{
	MecanumDrive_Polar(0.5, directionl, rotationl);
}
void MecanumDrivetrain::moveRight(float directionr, float rotationr)
{
	MecanumDrive_Polar(0.5, directionr, rotationr);
}

void MecanumDrivetrain::moveForwards(float speedf, float directionf, float rotationf)
{
	MecanumDrive_Polar(speedf, directionf, rotationf);
}
void MecanumDrivetrain::moveBackwards(float speedb, float directionb, float rotationb)
{
	MecanumDrive_Polar(speedb, directionb, rotationb);
}
void MecanumDrivetrain::moveLeft(float speedl, float directionl, float rotationl)
{
	MecanumDrive_Polar(speedl, directionl, rotationl);
}
void MecanumDrivetrain::moveRight(float speedr, float directionr, float rotationr)
{
	MecanumDrive_Polar(speedr, directionr, rotationr);
}

void MecanumDrivetrain::rotate(float angle)
{
	MecanumDrive_Polar(0.0, 0.0, angle);
}

void MecanumDrivetrain::stop()
{
	MecanumDrive_Polar(0.0, 0.0, 0.0);
}
