#ifndef Infrared_H
#define Infrared_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <AnalogInput.h>

class Infrared612: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	AnalogInput* infrared612;
public:
	Infrared612();
	void InitDefaultCommand();
};

#endif
