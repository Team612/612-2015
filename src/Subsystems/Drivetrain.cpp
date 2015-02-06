#include "../RobotMap.h"
#include <Talon.h>
#include <MotorSafetyHelper.h>
#include <Subsystems/Drivetrain.h>

DriveTrain::DriveTrain(uint32_t talonchannel1,
		                             uint32_t talonchannel2,
		                             uint32_t talonchannel3,
		                             uint32_t talonchannel4):
		Subsystem("Drivetrain"),
		RobotDrive(new Talon(talonchannel1),
				   new Talon(talonchannel2),
				   new Talon(talonchannel3),
				   new Talon(talonchannel4))

{
	SetSafetyEnabled(true);
	SetExpiration(MOTOR_EXPIRATION);
	std::printf("Expiration = %f", GetExpiration());
	//import trackball or something? idk.
}

void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::move(float magnitude, float direction, float rotation)
{
	MecanumDrive_Polar(magnitude, direction, rotation);
	m_safetyHelper->Feed();
}

void DriveTrain::stop()
{
	MecanumDrive_Polar(0.0f, 0.0f, 0.0f);
	m_safetyHelper->Feed();
}

bool DriveTrain::SwitchSensor(float distance) // Infared sensor is used by default zac likes to touhc children
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

void DriveTrain::CheckSensor(float distance)
{
	this->useIR = this->SwitchSensor(distance);
}
