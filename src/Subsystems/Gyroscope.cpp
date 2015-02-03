#include "Gyroscope.h"
#include <cstdio>

Gyroscope::Gyroscope() :
	Subsystem("Gyroscope")
{
	gyro = new Gyro(GYRO_CHANNEL);
	printf("Initializing Gyroscope on channel %u", GYRO_CHANNEL);
	gyro->InitGyro();

}

Gyroscope::~Gyroscope()
{
	delete gyro;
}

void Gyroscope::InitDefaultCommand()
{

}

// Other commands here

double Gyroscope::getRate()
{
	return gyro->GetRate();
}

float Gyroscope::getAngle()
{
	return gyro->GetAngle();
}

void Gyroscope::reset()
{
	printf("Resetting Gyroscope on channel %u", GYRO_CHANNEL);
	gyro->Reset();
}
