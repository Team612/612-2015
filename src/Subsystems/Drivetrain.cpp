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

	encoderLR = new Encoder(ENCODER_LR_A, ENCODER_LR_B); //The rear left encoder
	encoderLF = new Encoder(ENCODER_LF_A, ENCODER_LF_B); //The front left encoder
	encoderRR = new Encoder(ENCODER_RR_A, ENCODER_RR_B); //The rear right encoder
	encoderRF = new Encoder(ENCODER_RF_A, ENCODER_RF_B); //The front right encoder
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
	static int count = 0;
	if (count % 120 == 0)
	{
		std::printf("LF Encoder Value %u\n", encoderLF->Get());
		std::printf("LR Encoder Value %u\n", encoderLR->Get());
		std::printf("RF Encoder Value %u\n", encoderRF->Get());
		std::printf("RR Encoder Value %u\n", encoderRR->Get());
	}

	count++;
}

void Drivetrain::stop()
{
	MecanumDrive_Cartesian(0.0f, 0.0f, 0.0f);
}

void Drivetrain::moveTank(float l, float r)
{
	TankDrive(l, r);
}

Encoder* Drivetrain::getLFEncoder()
{
	return encoderLF;
}

Encoder* Drivetrain::getLREncoder()
{
	return encoderLR;
}

Encoder* Drivetrain::getRFEncoder()
{
	return encoderRF;
}

Encoder* Drivetrain::getRREncoder()
{
	return encoderRR;
}

