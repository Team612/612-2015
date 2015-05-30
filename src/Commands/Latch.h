#ifndef Latch_H
#define Latch_H

#include "RobotMap.h"
#include "../CommandBase.h"
#include "WPILib.h"
#include <Timer.h>
#include <DoubleSolenoid.h>

class Latch: public CommandBase
{
public:;
	Latch(DoubleSolenoid* sol, DoubleSolenoid::Value val);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	static const DoubleSolenoid::Value OPEN = DoubleSolenoid::kReverse;
	static const DoubleSolenoid::Value CLOSE = DoubleSolenoid::kForward;

private:
	DoubleSolenoid* commandSol;
	DoubleSolenoid::Value direction;
	Timer* timer;
};

#endif
