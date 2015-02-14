#ifndef LatchOpen_H
#define LatchOpen_H

#include "RobotMap.h"
#include "../CommandBase.h"
#include "WPILib.h"
#include <Timer.h>
#include <DoubleSolenoid.h>

class LatchOpen: public CommandBase
{
public:
	Timer* timer;
	LatchOpen();
	void Initialize();
	void End();
private:
	DoubleSolenoid* firstsolenoid;
	DoubleSolenoid* secondsolenoid;
};

#endif
