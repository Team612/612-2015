#include "Gyroscope.h"

Gyroscope::Gyroscope() :
	Subsystem("Gyroscope")
{
	this->gyro = new Gyro(GYRO_CHANNEL);
}

Gyroscope::~Gyroscope()
{
	delete this->gyro;
}

void Gyroscope::InitDefaultCommand()
{
	//SetDefaultCommand(new GyroscopeUp());
}

// Other commands here
