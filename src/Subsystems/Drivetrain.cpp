#include "../RobotMap.h"
#include <Talon.h>
#include <MotorSafetyHelper.h>
#include <Subsystems/Drivetrain.h>

Drivetrain::Drivetrain(uint32_t talonchannel1,
		                             uint32_t talonchannel2,
		                             uint32_t talonchannel3,
		                             uint32_t talonchannel4):
		Subsystem("MecanumDrivetrain"),
		RobotDrive(new Talon(talonchannel1),
				   new Talon(talonchannel2),
				   new Talon(talonchannel3),
				   new Talon(talonchannel4))

{
	SetSafetyEnabled(true);
	SetExpiration(MOTOR_EXPIRATION);
	std::printf("Expiration = %f", GetExpiration());
	//import trackball or something? idk.

	encoderLR = new Encoder(ENCODER_LR_A, ENCODER_LR_B); //The rear left encoder
	encoderLF = new Encoder(ENCODER_LF_A, ENCODER_LF_B); //The front left encoder
	encoderRR = new Encoder(ENCODER_RR_A, ENCODER_RR_B); //The rear right encoder
	encoderRF = new Encoder(ENCODER_RF_A, ENCODER_RF_B); //The front right encoder

}

void Drivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::move(float magnitude, float direction, float rotation)
{
	MecanumDrive_Polar(magnitude, direction, rotation);
	m_safetyHelper->Feed();
}

void Drivetrain::stop()
{
	MecanumDrive_Polar(0.0f, 0.0f, 0.0f);
	m_safetyHelper->Feed();
}

bool Drivetrain::SwitchSensor(float distance) // Infared sensor is used by default
{
	// Once the IR becomes accurate, switch to it over ultrasonic
	return (distance < 6);

	// OLD
	/*
	if(d < 6)
	{
		return true;
	}
	else
	{
		return false;
	} */
}

void Drivetrain::CheckSensor(float distance)
{
	this->useIR = this->SwitchSensor(distance);
}

void Drivetrain::resetEncoders()
{
	encoderLR->Reset();
	encoderLF->Reset();
	encoderRR->Reset();
	encoderRF->Reset();
}

int32_t Drivetrain::getDistance(MotorLocation motor)
{
	//Switches through and returns the current encoder value
	switch(motor)
	{
	case LEFT_FRONT:
		return encoderLF->Get();
		break;
	case LEFT_REAR:
		return encoderLR->Get();
		break;
	case RIGHT_FRONT:
		return encoderRF->Get();
		break;
	case RIGHT_REAR:
		return encoderRR->Get();
		break;
	}
}

