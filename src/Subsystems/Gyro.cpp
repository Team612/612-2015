#include "Gyro.h"

Gyro::Gyro() :
	Subsystem("Gyro")
{
	talon = new Talon(Gyro_MOTOR);
	topSwitch = new DigitalInput(Gyro_TOP_SWITCH);
	bottomSwitch = new DigitalInput(Gyro_BOTTOM_SWITCH);
	encoder = new Encoder(Gyro_ENCODER_A, Gyro_ENCODER_B);
}

Gyro::~Gyro()
{
	delete talon;
}

void Gyro::InitDefaultCommand()
{
	//SetDefaultCommand(new GyroUp());
}

void Gyro::move(float magnitude)
{
	//Checks the sensors to see if the Gyro is at the top or the bottom
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

void Gyro::stop()
{
	//Sets motor speed to nothing
	talon->Set(0);
}

Encoder* Gyro::getEncoder()
{
	return encoder;
}

