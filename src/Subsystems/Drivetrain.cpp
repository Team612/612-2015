#include "Drivetrain.h"
#include "../RobotMap.h"

Drivetrain::Drivetrain():
		Subsystem("Drivetrain"),
		RobotDrive(TALON_FL, TALON_RL, TALON_FR, TALON_RR)
{
	SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
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

void Drivetrain::stop()
{
	MecanumDrive_Polar(0.0f, 0.0f, 0.0f);
}
