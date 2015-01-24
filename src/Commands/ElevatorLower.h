#ifndef ElevatorLower_H
#define ElevatorLower_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorLower: public CommandBase
{
public:
	ElevatorLower();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
