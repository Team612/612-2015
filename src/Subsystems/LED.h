#ifndef LED_H
#define LED_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LED: public Subsystem
{
private:
	DigitalOutput* LeftLEDGreen;
	DigitalOutput* LeftLEDRed;
	DigitalOutput* RightLEDGreen;
	DigitalOutput* RightLEDRed;
public:
	LED();
	void InitDefaultCommand();
	void setGreen(bool);
	void setRed(bool);
};

#endif
