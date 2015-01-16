#ifndef ELEVATOR_DOWN_H
#define ELEVATOR_DOWN_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorDown: public CommandBase
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
