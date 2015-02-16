#ifndef ElevatorUp_H
#define ElevatorUp_H

#include "WPILib.h"
#include "../CommandBase.h"

class ElevatorUp: public CommandBase
{
public:
	ElevatorUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
