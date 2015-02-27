#ifndef Autonomous_H
#define Autonomous_H

#include "../CommandBase.h"
#include "WPILib.h"

class Autonomous: public CommandBase
{
public:
	Autonomous();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
