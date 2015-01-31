#include "Drivetrain.h"
#include "../RobotMap.h"
#include <MotorSafetyHelper.h>

Drivetrain::Drivetrain():
		Subsystem("Drivetrain"),
		RobotDrive(new CANTalon(TALON_FL), new CANTalon(TALON_RL), new CANTalon(TALON_FR), new CANTalon(TALON_RR))
{
	SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	SetSafetyEnabled(true);
	//SetExpiration(10.0f);
	this->m_safetyHelper->SetExpiration(100.0f);
	std::printf("Expiration = %f", GetExpiration());
}

void Drivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::move(float x, float y, float rotation)
{
	//after much testing, we discovered that mec drive works if we swap the rotation and x coordinate values. dont know why
/*
	float temp = rotation; //create temporary variable to hold
	rotation = x; //put x into rotation
	x = temp; //now variables are fully swapped
*/
	// FEED ME SEYMOUR
	this->m_safetyHelper->Feed();
	this->

	//now that they are swapped, plug them in correctly
	MecanumDrive_Cartesian(x*THROTTLE,y*THROTTLE,rotation*THROTTLE); //for some reason, this works if x and rotation are swapped
	//in case we need to debug
	#ifdef DEBUG
		static int count = 0;
		if (count % 30 == 0)
		{
			std::printf("X = %f\t Y = %f\tR = %f\n\n", x, y,rotation);
			if (!m_safetyHelper->IsAlive())
			{
				std::printf("Motor has been timed out!\n");
			}
		}
		count++;
	#endif
}

void Drivetrain::stop()
{
	MecanumDrive_Cartesian(0.0f, 0.0f, 0.0f);
}
