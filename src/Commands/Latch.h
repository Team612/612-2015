#ifndef Latch_H
#define Latch_H

#include "RobotMap.h"
#include "../CommandBase.h"
#include "WPILib.h"
#include <Timer.h>
#include <DoubleSolenoid.h>

class Latch: public CommandBase
{
public:
	Timer* timer;
	Latch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	DoubleSolenoid* solenoid;
	enum action {Open, Close};
	action openClose;
};

#endif
