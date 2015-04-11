#include "NavX_IMU.h"
#include "../RobotMap.h"

NavX_IMU::NavX_IMU() :
		Subsystem("ExampleSubsystem")
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
