#include "NavX_IMU.h"
#include "../RobotMap.h"

NavX_IMU::NavX_IMU() :
		Subsystem("NavX_IMU")
{
	navX = new AHRS(NAVX_PORT, UPDATE_RATE_HZ);
}

void NavX_IMU::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

bool NavX_IMU::IsRobotMoving()
{
	return navX->IsMoving();
}

bool NavX_IMU::IsRobotRotating()
{
	return navX->IsRotating();
}

float NavX_IMU::GetXVelocity()
{
	return navX->GetVelocityX();
}

float NavX_IMU::GetYVelocity()
{
	return navX->GetVelocityY();
}

short NavX_IMU::GetXMagnetometer()
{
	return navX->GetCalibratedMagnetometerX();
}

short NavX_IMU::GetYMagnetometer()
{
	return navX->GetCalibratedMagnetometerY();
}

short NavX_IMU::GetZMagnetometer()
{
	return navX->GetCalibratedMagnetometerZ();
}
