
#include "Vision.h"
#include "RobotMap.h"

Vision::Vision() :
		Subsystem("Vision")
{
	i2c = new I2C(I2C::kOnboard, 2);
	Update();
}

void Vision::InitDefaultCommand()
{

}

void Vision::Update()
{
	static uint8_t* buffer = new uint8_t[7];
	i2c->ReadOnly(7, buffer);
	//CommandBase::pixellogic->I2CRecieve();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
