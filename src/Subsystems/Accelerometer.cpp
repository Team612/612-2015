#include "Accelerometer.h"

Accelerometer::Accelerometer() :
	Subsystem("Accelerometer")
{
	talon = new Talon(Accelerometer_MOTOR);
	topSwitch = new DigitalInput(Accelerometer_TOP_SWITCH);
	bottomSwitch = new DigitalInput(Accelerometer_BOTTOM_SWITCH);
	encoder = new Encoder(Accelerometer_ENCODER_A, Accelerometer_ENCODER_B);
}

Accelerometer::~Accelerometer()
{
	delete talon;
}

void Accelerometer::InitDefaultCommand()
{
	//SetDefaultCommand(new AccelerometerUp());
}

void Accelerometer::move(float magnitude)
{
	//Checks the sensors to see if the Accelerometer is at the top or the bottom
	bool topInput = topSwitch->Get();
	bool bottomInput = bottomSwitch->Get();

	//If the sensors give any input then the motors are set to a speed of 0
	if (topInput || bottomInput)
	{
		talon->Set(0);
	}
	else
	{
		talon->Set(magnitude);
	}
}

void Accelerometer::stop()
{
	//Sets motor speed to nothing
	talon->Set(0);
}

Encoder* Accelerometer::getEncoder()
{
	return encoder;
}

