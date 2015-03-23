#ifndef ElevatorStop_H
#define ElevatorStop_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorStop: public CommandBase
{
public:
	ElevatorStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
