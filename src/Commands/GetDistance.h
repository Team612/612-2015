#ifndef GetDistance_H
#define GetDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class GetDistance: public CommandBase
{
public:
	GetDistance();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	bool isGDDone;
};

#endif
