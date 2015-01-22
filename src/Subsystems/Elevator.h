#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Elevator: public Subsystem
{
private:
	Talon* controller;
public:
	Elevator(uint32_t channel);
	void InitDefaultCommand();
	void move(float magnitude);
	void stop();
};

#endif

