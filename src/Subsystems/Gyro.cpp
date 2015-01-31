#include "Gyroscope.h"

Gyroscope::Gyroscope() :
	Subsystem("Gyroscope")
{
	talon = new Talon(Gyroscope_MOTOR);
	topSwitch = new DigitalInput(Gyroscope_TOP_SWITCH);
	bottomSwitch = new DigitalInput(Gyroscope_BOTTOM_SWITCH);
	encoder = new Encoder(Gyroscope_ENCODER_A, Gyroscope_ENCODER_B);
}

Gyroscope::~Gyroscope()
{
	delete talon;
}

void Gyroscope::InitDefaultCommand()
{
	//SetDefaultCommand(new GyroscopeUp());
}

void Gyroscope::move(float magnitude)
{
	//Checks the sensors to see if the Gyroscope is at the top or the bottom
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

void Gyroscope::stop()
{
	//Sets motor speed to nothing
	talon->Set(0);
}

Encoder* Gyroscope::getEncoder()
{
	return encoder;
}

