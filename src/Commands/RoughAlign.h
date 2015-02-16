#ifndef RoughAlign_H
#define RoughAlign_H

#include "../CommandBase.h"
#include "WPILib.h"

class RoughAlign: public CommandBase
{
private:
	float distanceToTote;
	float bearingToTote;
	float distanceToBeAway;
	bool done = false;
public:
	RoughAlign(float d, float b, float dw);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
