#ifndef Ultrasonic_H
#define Ultrasonic_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <Ultrasonic.h>
#include <DigitalOutput.h>
#include <DigitalInput.h>

class Ultrasonic: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DigitalInput* ultraDI_1;
	DigitalOutput* ultraDO_1;

	DigitalInput* ultraDI_2;
	DigitalOutput* ultraDO_2;

	Ultrasonic* ultrasonicL;
	Ultrasonic* ultrasonicR;
public:
	Ultrasonic();
	void InitDefaultCommand();
	double measureL();
	double measureR();
};

#endif
