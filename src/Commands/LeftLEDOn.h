#ifndef LeftLEDON_H
#define LeftLEDON_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../RobotMap.h"

class LeftLEDOn: public CommandBase
{
private:
	DigitalOutput* LeftLEDGreen;
	DigitalOutput* LeftLEDRed;
public:
	LeftLEDOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
