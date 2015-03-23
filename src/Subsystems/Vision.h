
#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PixelLogic.h"
//#include "../CommandBase.h"

class Vision: public Subsystem
{
private:
	I2C *i2c;

public:
	Vision();
	void InitDefaultCommand();
	void Update();
};

#endif
