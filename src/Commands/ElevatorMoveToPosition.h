#ifndef ElevatorMoveToPosition_H
#define ElevatorMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorMoveToPosition: public CommandBase
{
private:
	uint32_t position;
public:
	ElevatorMoveToPosition(uint32_t position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
