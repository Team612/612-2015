#ifndef ElevatorUp_H
#define ElevatorUp_H

#include "../CommandBase.h"
#include "WPILib.h"

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
