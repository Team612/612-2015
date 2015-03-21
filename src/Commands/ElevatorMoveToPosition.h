#ifndef ElevatorMoveToPosition_H
#define ElevatorMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

class ElevatorMoveToPosition: public CommandBase
{
private:

public:
	ElevatorMoveToPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
