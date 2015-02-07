#include "../RobotMap.h"
#include <Talon.h>
#include <MotorSafetyHelper.h>
#include "Drivetrain.h"

Drivetrain::Drivetrain(uint32_t talonchannel1,
		                             uint32_t talonchannel2,
		                             uint32_t talonchannel3,
		                             uint32_t talonchannel4,
									 uint32_t infraredchannel):
		Subsystem("Drivetrain"),
		RobotDrive(new Talon(talonchannel1),
				   new Talon(talonchannel2),
				   new Talon(talonchannel3),
				   new Talon(talonchannel4))

{
	SetSafetyEnabled(true);
	SetExpiration(MOTOR_EXPIRATION);
	std::printf("Expiration = %f", GetExpiration());
	ir = new AnalogInput(infraredchannel);

	encoderLF = new Encoder(ENCODER_LF_A, ENCODER_LF_B);
	encoderLR = new Encoder(ENCODER_LR_A, ENCODER_LR_B);
	encoderRF = new Encoder(ENCODER_RF_A, ENCODER_RF_B);
	encoderRR = new Encoder(ENCODER_RR_A, ENCODER_RR_B);

	//import trackball or something? idk.
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

int16_t Drivetrain::getir()
{
	return ir->GetValue();
}

void Drivetrain::resetEncoders()
{
	//Calls reset on all encoders
	encoderLF->Reset();
	encoderLR->Reset();
	encoderRF->Reset();
	encoderRR->Reset();
}

int32_t Drivetrain::getDistance(MotorLocation motor)
{
	//Switch statement to check for the encoder distance
	//Did not use break statements because the return statement will end the method anyways
	switch(motor)
	{
	case LEFT_FRONT:
		return encoderLF->Get();
	case LEFT_REAR:
		return encoderLR->Get();
	case RIGHT_FRONT:
		return encoderRF->Get();
	case RIGHT_REAR:
		return encoderRR->Get();
	default:
		return 0; //In case the enum somehow gets an addition
	}
}

/*bool Drivetrain::SwitchSensor(float distance) // Infared sensor is used by default
{
	//TODO: Implement auto switching between IR and Ultrasonic
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
	}
}

void Drivetrain::CheckSensor(float distance)
{
	this->useIR = this->SwitchSensor(distance);
}
*/
