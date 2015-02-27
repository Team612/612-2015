#include "../RobotMap.h"
#include <Talon.h>
#include <MotorSafetyHelper.h>
#include "Drivetrain.h"

Drivetrain::Drivetrain(CANTalon* t_fl, CANTalon* t_fr, CANTalon* t_rl, CANTalon* t_rr, AnalogInput* infrared):
		Subsystem("Drivetrain"),
		RobotDrive(t_fl, t_fr, t_rl, t_rr)
{
	fl = t_fl;
	fr = t_fr;
	rl = t_rl;
	rr = t_rr;

	fl->SetFeedbackDevice(CANTalon::QuadEncoder);
	fr->SetFeedbackDevice(CANTalon::QuadEncoder);
	rl->SetFeedbackDevice(CANTalon::QuadEncoder);
	rr->SetFeedbackDevice(CANTalon::QuadEncoder);

	SetSafetyEnabled(false);
	//SetExpiration(MOTOR_EXPIRATION);
	std::printf("Expiration = %f", GetExpiration());
	ir = infrared;

	//encoderLF = new Encoder(ENCODER_LF_A, ENCODER_LF_B);
	//encoderLR = new Encoder(ENCODER_LR_A, ENCODER_LR_B);
	//encoderRF = new Encoder(ENCODER_RF_A, ENCODER_RF_B);
	//encoderRR = new Encoder(ENCODER_RR_A, ENCODER_RR_B);

	/**
	 * rear left clockwise = backwards
	 * rear right clockwise = forwards
	 * front right clockwise = forwards
	 * front left clockwise = backwards
	 */

	//SetInvertedMotor(kRearRightMotor, true);
	SetInvertedMotor(kRearRightMotor, true);
	//SetInvertedMotor(kFrontRightMotor, true);
	SetInvertedMotor(kFrontRightMotor, true);

	//import trackball or something? idk.
}

void Drivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::move(float x, float y, float rotation)
{
	//printf("MoveY %f\n", y);
	MecanumDrive_Cartesian(x, y, rotation);
	//printf("MoveX %f\n", x);
	// FEED ME SEYMORE
	m_safetyHelper->Feed();
}

void Drivetrain::stop()
{
	MecanumDrive_Cartesian(0.0f, 0.0f, 0.0f);
	// FEED ME SEYMORE
	m_safetyHelper->Feed();
}

int16_t Drivetrain::getir()
{
	return ir->GetValue();
}

/*void Drivetrain::resetEncoders()
{
	//So this seems pretty useless, im gonna comment this out to avoid messing things up.
	encoderLF->Reset();
	encoderLR->Reset();
	encoderRF->Reset();
	encoderRR->Reset();
}*/

int32_t Drivetrain::getDistance(MotorLocation motor)
{
	//Switch statement to check for the encoder distance
	//Did not use break statements because the return statement will end the method anyways
	switch(motor)
	{
	case LEFT_FRONT:

	case LEFT_REAR:

	case RIGHT_FRONT:

	case RIGHT_REAR:

	default:
		return 0;
	}
}

/*bool Drivetrain::SwitchSensor(float distance) // Infared sensor is used by default
{
	//TODO: Implement auto switching between IR and Ultrasonic
	// Once the IR becomes accurate, switch to it over ultrasonic
	return (distance < 6);

	// OLD

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
