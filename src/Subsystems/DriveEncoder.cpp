#include "DriveEncoder.h"
#include "../RobotMap.h"

DriveEncoder::DriveEncoder() :
		Subsystem("Encoder")
{
	encoders[0] = new Encoder(ENCODER_LR_A, ENCODER_LR_B); //The rear left encoder
	encoders[1] = new Encoder(ENCODER_LF_A, ENCODER_LF_B); //The front left encoder
	encoders[2] = new Encoder(ENCODER_RR_A, ENCODER_RR_B); //The rear right encoder
	encoders[3] = new Encoder(ENCODER_RF_A, ENCODER_RF_B); //The front right encoder
}

DriveEncoder::~DriveEncoder()
{
	delete encoders; //deletes encoders for more resources
}

int32_t DriveEncoder::GetEncoderSpins(uint32_t encoder) //returns the spin from the encoder you want
{
	return encoders[encoder]->Get();
}

double DriveEncoder::GetEncoderDistance(uint32_t encoder) //returns the spin from the encoder you want
{
	return encoders[encoder]->GetDistance();
}

double DriveEncoder::GetEncoderRate(uint32_t encoder) //returns the spin from the encoder you want
{
	return encoders[encoder]->GetRate();
}

void DriveEncoder::ResetAllEncoders() //reset the distance total on all encoders
{
	for (int index = 0; index < 4; index++)
	{
		printf("Resetting all drive encoders");
		encoders[index]->Reset();
	}
}

void DriveEncoder::ResetEncoder(uint32_t encoder) //reset the distance total on the encoder you want
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
