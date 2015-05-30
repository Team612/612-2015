#ifndef ElevatorUp_H
#define ElevatorUp_H

#include "WPILib.h"
#include "../CommandBase.h"
#include "RobotMap.h"

class ElevatorUp: public CommandBase
{
public:
	ElevatorUp();///<ElevatorUp constructor
	void Initialize(); ///<Initializes command
	void Execute(); ///<Moves the elevator up at 1.0f
	bool IsFinished(); ///<Returns false
	void End(); ///<Stop elevator
	void Interrupted(); ///<Stop elevator
};

#endif
