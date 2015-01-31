#include "DriveEncoder.h"
#include "../RobotMap.h"

DriveEncoder::DriveEncoder() :
		Subsystem("Encoder")
{
	encoders[0] = new Encoder(ENCODER_LR_A, ENCODER_LR_B);
	encoders[1] = new Encoder(ENCODER_LF_A, ENCODER_LF_B);
	encoders[2] = new Encoder(ENCODER_RR_A, ENCODER_RR_B);
	encoders[3] = new Encoder(ENCODER_RF_A, ENCODER_RF_B);
}

DriveEncoder::~DriveEncoder()
{
	delete encoders;
}

int32_t DriveEncoder::getSpins(uint32_t encoder)
{
	return encoders[encoder]->Get();
}

double DriveEncoder::getDistance(uint32_t encoder)
{
	return encoders[encoder]->GetDistance();
}

double DriveEncoder::getRate(uint32_t encoder)
{
	return encoders[encoder]->GetRate();
}

void DriveEncoder::reset()
{
	for (int index = 0; index < 4; index++)
	{
		printf("Resetting all drive encoders");
		encoders[index]->Reset();
	}
}

void DriveEncoder::reset(uint32_t encoder)
{
	printf("Resetting drive encoder #%u", encoder);
	encoders[encoder]->Reset();
}

void DriveEncoder::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
