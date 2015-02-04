#ifndef AverageDistance_H
#define AverageDistance_H

#include <Subsystems/612Ultrasonic.h>
#include "../CommandBase.h"
#include "WPILib.h"

class AverageDistance: public CommandBase
{
public:
	AverageDistance();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	bool isADDone;
};

#endif
