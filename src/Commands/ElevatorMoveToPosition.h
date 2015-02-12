#ifndef ElevatorMoveToPosition_H
#define ElevatorMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorMoveToPosition: public CommandBase
{
private:
	uint32_t targetPosition;
	int targetSpins;
	const int presets[4] = {0,1,2,3,4}; //filler value! TODO add real preset values!
	const uint32_t INTERVAL = 0; //Placeholder value TODO add real values!
public:
	ElevatorMoveToPosition(uint32_t position); //example of use: ElevatorMoveToPosition(0);
	//This would (hopefully) move the elevator to the first value in const int presets array, which is zero.
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
