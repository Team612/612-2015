#ifndef ActivateSolenoid_H
#define ActivateSolenoid_H

#include "../CommandBase.h"
#include "WPILib.h"

class ActivateSolenoid: public CommandBase
{
private:
	Timer* timer;
	uint32_t targetTime;
	DoubleSolenoid* solenoid;
	DoubleSolenoid::Value solenoidState;
public:
	ActivateSolenoid(DoubleSolenoid* solenoid_, DoubleSolenoid::Value value, uint32_t time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
