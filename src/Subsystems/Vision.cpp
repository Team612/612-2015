#include "Vision.h"
#include "RobotMap.h"

typedef unsigned char uint8_t;

Vision::Vision() :
		Subsystem("Vision")
{
	i2c = new I2C(I2C::kOnboard, DEVICE_ADDRESS); //Initializes
}

void Vision::InitDefaultCommand()
{

}

void Vision::updateVisionRead()
{

}

void Vision::updateVisonWrite()
{

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
