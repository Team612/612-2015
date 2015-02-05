#ifndef Ultrasonic_H
#define Ultrasonic_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <Ultrasonic.h>
#include <DigitalOutput.h>
#include <DigitalInput.h>

class Ultrasonic612: public Subsystem
{
private:
	uint32_t ultraDI_1;
	uint32_t ultraDO_1;

	uint32_t ultraDI_2;
	uint32_t ultraDO_2;

	Ultrasonic* ultrasonicL;
	Ultrasonic* ultrasonicR;
public:
	Ultrasonic612();
	void InitDefaultCommand();
	double measureL();
	double measureR();
};

#endif
