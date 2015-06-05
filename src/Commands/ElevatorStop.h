#ifndef ElevatorStop_H
#define ElevatorStop_H

#include "../CommandBase.h"
#include "WPILib.h"

class ElevatorStop: public CommandBase
{
public:
	ElevatorStop(); ///<Constructor
	void Initialize();///<Initializer
	void Execute(); ///<Stops the elevator
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
