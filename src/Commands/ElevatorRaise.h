#ifndef ElevatorRaise_H
#define ElevatorRaise_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorRaise: public CommandBase
{
public:
	ElevatorRaise();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
