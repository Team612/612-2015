#ifndef ElevatorMoveToPosition_H
#define ElevatorMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorMoveToPosition: public CommandBase
{
private:
	uint32_t targetPosition;
	int targetSpins;
	const uint32_t INTERVAL = 1; //TODO Placeholder value
public:
	ElevatorMoveToPosition(uint32_t position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
