#include <Subsystems/DriveAccelerometer.h>

DriveAccelerometer::DriveAccelerometer() :
	Subsystem("Accelerometer")
{
	accel = new BuiltInAccelerometer();
}

DriveAccelerometer::~DriveAccelerometer()
{
	delete accel;
}

void DriveAccelerometer::InitDefaultCommand()
{
}

// Other methods here
double DriveAccelerometer::GetX()
{
	return accel->GetX();
}

double DriveAccelerometer::GetY()
{
	return accel->GetY();
}

double DriveAccelerometer::GetZ()
{
	return accel->GetZ();
}
