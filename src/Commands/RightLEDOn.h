#ifndef RightLEDON_H
#define RightLEDON_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../RobotMap.h"

class RightLEDOn: public CommandBase
{
private:
	DigitalOutput* RightLEDGreen;
	DigitalOutput* RightLEDRed;

public:
	RightLEDOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
