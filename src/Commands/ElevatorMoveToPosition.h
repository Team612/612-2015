#ifndef ElevatorMoveToPosition_H
#define ElevatorMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

class ElevatorMoveToPosition: public CommandBase
{
private:
	uint32_t targetPosition; ///<Position you want to move target to
	int targetSpins; ///<position*interval (constant)
	const uint32_t INTERVAL = 1; ///<TODO Placeholder value
public:
	///Moves elevator to certain location
	///@param position position to move it to
	ElevatorMoveToPosition(uint32_t position);
	void Initialize(); ///<Initializer
	void Execute(); ///<Keeps elevator moving in correct direction
	bool IsFinished(); ///<Tests if it's at target position
	void End();
	void Interrupted();
};

#endif
