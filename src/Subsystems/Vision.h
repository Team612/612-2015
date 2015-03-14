#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Vision: public Subsystem
{
private:
	I2C* i2c;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Vision();
	void InitDefaultCommand();

	void updateVision();
};

#endif
