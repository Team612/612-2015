#ifndef ElevatorDown_H
#define ElevatorDown_H

#include "../CommandBase.h"
#include "WPILib.h"

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
