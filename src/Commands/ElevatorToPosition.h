#ifndef ELEVATOR_TO_POSITION_H
#define ELEVATOR_TO_POSITION_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorToPosition: public CommandBase
{
public:
	ExampleCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
