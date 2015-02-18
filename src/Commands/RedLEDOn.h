#ifndef RightLEDOn_H
#define RightLEDOn_H

#include "../CommandBase.h"
#include "WPILib.h"

class RedLEDOn: public CommandBase
{
public:
	RedLEDOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
