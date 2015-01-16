#ifndef ELEVATOR_UP_H
#define ELEVATOR_UP_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorUp: public CommandBase
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
