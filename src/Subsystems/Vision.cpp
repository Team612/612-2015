#include "Vision.h"
#include "RobotMap.h"

Vision::Vision() :
		Subsystem("Vision")
{
	i2c = new I2C(I2C::kOnboard, 2); //Initializes
}

void Vision::InitDefaultCommand()
{

}

void Vision::updateVision()
{
	static uint8_t* data = new uint8_t[7];
	for (int i = 0; i < 7; i++)
		data[i] = 0;

	i2c->ReadOnly(5, data);
	printf("I2C: %u\n", data[0]);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
