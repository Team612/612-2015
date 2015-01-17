#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "../CommandBase.h"
#include "WPILib.h"

class Elevator: public CommandBase
{
public:
	Elevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* EXAMPLE_COMMAND_H */
