#ifndef ElevatorDown_H
#define ElevatorDown_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

class ElevatorDown: public CommandBase
{
public:
	ElevatorDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
