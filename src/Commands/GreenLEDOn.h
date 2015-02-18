#ifndef GreenLEDOn_H
#define GreenLEDOn_H

#include "../CommandBase.h"
#include "WPILib.h"

class GreenLEDOn: public CommandBase
{
public:
	GreenLEDOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
