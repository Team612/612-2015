#include "Accelerometer.h"

Accelerometer::Accelerometer() :
	Subsystem("Accelerometer")
{
	this->accel = new BuiltInAccelerometer();
}

Accelerometer::~Accelerometer()
{
	delete accel;
}

void Accelerometer::InitDefaultCommand()
{
}

// Other methods here
double Accelerometer::GetX()
{
	return this->accel.GetX();
}

double Accelerometer::GetY()
{
	return this->accel.GetY();
}

double Accelerometer::GetZ()
{
	return this->accel.GetZ();
}
