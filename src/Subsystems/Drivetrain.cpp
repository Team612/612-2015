#include "../RobotMap.h"
#include <Talon.h>
#include <MotorSafetyHelper.h>
#include "Drivetrain.h"

Drivetrain::Drivetrain(CANTalon* t_fl, CANTalon* t_fr, CANTalon* t_rl, CANTalon* t_rr, AnalogInput* infrared):
		Subsystem("Drivetrain"),
		RobotDrive(t_fl, t_fr, t_rl, t_rr)
{
	imu = new IMU(new SerialPort(57600,SerialPort::kMXP),REFRESH_RATE);
	motor_power = 1.0f;
	fl = t_fl;
	fr = t_fr;
	rl = t_rl;
	rr = t_rr;


	fl->SetFeedbackDevice(CANTalon::QuadEncoder);
	//fl->SetControlMode(CANSpeedController::kPosition);
	fr->SetFeedbackDevice(CANTalon::QuadEncoder);
	//fr->SetControlMode(CANSpeedController::kPosition);
	rl->SetFeedbackDevice(CANTalon::QuadEncoder);
	//rl->SetControlMode(CANSpeedController::kPosition);
	rr->SetFeedbackDevice(CANTalon::QuadEncoder);
	//rr->SetControlMode(CANSpeedController::kPosition);
	resetEncoders();

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
	//std::printf("Gyro = %f\n", imu->GetYaw());
	//printf("MoveY: THIS IS DRIVETRAIN %f\n", y);
#ifdef IMU
	MecanumDrive_Cartesian(x, y, imu->GetYaw());
#else
	MecanumDrive_Cartesian(x, y, rotation);
#endif
	//printf("MoveX %f\n", x);
	// FEED ME SEYMORE
	m_safetyHelper->Feed();
}

void Drivetrain::stop()
{
	MecanumDrive_Cartesian(0.0f, 0.0f, 0.0f);
	printf("STOP \n");
	// FEED ME SEYMORE
	m_safetyHelper->Feed();
}

int16_t Drivetrain::getir()
{
	return ir->GetValue();
}

void Drivetrain::resetEncoders()
{
	//encoderLF->Reset();
	//encoderLR->Reset();
	//encoderRF->Reset();
	//encoderRR->Reset();
	//fl->Set(0.0f);
	//fr->Set(0.0f);
	//rl->Set(0.0f);
	//rr->Set(0.0f);
	fl->SetPosition(0.0f);
	fr->SetPosition(0.0f);
	rl->SetPosition(0.0f);
	rr->SetPosition(0.0f);

}

float Drivetrain::reverseDistances(bool fr, bool rr, bool fl, bool rl)
{
	int distfr = getDistance(FRONT_RIGHT) * (fr? -1: 1);
	int distrr = getDistance(REAR_RIGHT) * (rr? -1: 1);
	int distfl = getDistance(FRONT_LEFT) * (fl? -1: 1);
	int distrl = getDistance(REAR_LEFT) * (rl? -1: 1);

	return ((float)distfr + (float)distrr + (float)distfl + (float)distrl) / 4;
}

float Drivetrain::getAverageDistanceX()
{
	return reverseDistances(false, false, true, true);
}

float Drivetrain::getAverageDistanceY()
{
	return reverseDistances(false, true, false, true);
}

int Drivetrain::getDistance(MotorLocation motor)
{
	switch(motor)
	{
	case FRONT_LEFT:
		return (fl->GetEncPosition());
		break;
	case FRONT_RIGHT:
		return (fr->GetEncPosition());
		break;
	case REAR_LEFT:
		return (rl->GetEncPosition());
		break;
	case REAR_RIGHT:
		return (rr->GetEncPosition());
		break;
	case FRONT_AVERAGE:
		return (getDistance(FRONT_LEFT)+getDistance(FRONT_RIGHT)/2.0f);
		break;
	case RIGHT_AVERAGE:
		return (getDistance(FRONT_RIGHT)+getDistance(REAR_RIGHT)/2.0f);
		break;
	case REAR_AVERAGE:
		return (getDistance(REAR_RIGHT)+getDistance(REAR_LEFT)/2.0f);
		break;
	case LEFT_AVERAGE:
		return (getDistance(FRONT_LEFT)+getDistance(REAR_LEFT)/2.0f);
		break;
	case MAJOR_DIAGONAL:
		return (getDistance(FRONT_LEFT)+getDistance(REAR_RIGHT)/2.0f);
		break;
	case MINOR_DIAGONAL:
		return (getDistance(FRONT_RIGHT)+getDistance(REAR_LEFT)/2.0f);
		break;
	case ALL_AVERAGE:
		return (getDistance(FRONT_LEFT)+getDistance(FRONT_RIGHT)+getDistance(REAR_LEFT)+getDistance(REAR_RIGHT)/4.0f);
		break;
	default:
		return 0;
		break;
	}
}
