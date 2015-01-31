#include "Accelerometer.h"

Accelerometer::Accelerometer() :
	Subsystem("Accelerometer")
{
}

Accelerometer::~Accelerometer()
{
	delete accel;
}

void Accelerometer::InitDefaultCommand()
{
}

// Other methods here
