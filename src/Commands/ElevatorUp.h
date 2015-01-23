#ifndef ElevatorUp_H
#define ElevatorUp_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorUp: public CommandBase
{
private:
	uint32_t rotations;
public:
	ElevatorUp(uint32_t inRotations);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
