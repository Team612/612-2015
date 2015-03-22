#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Vision: public Subsystem
{
private:
	I2C* rcam;
	I2C* lcam;

	uint32_t convertToInteger(uint8_t bytes[]);
	float convertToFloat(uint8_t bytes[]);

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Vision();
	void InitDefaultCommand();
	void updateVisionRead();
};

#endif
