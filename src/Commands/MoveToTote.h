#ifndef MoveToTote_H
#define MoveToTote_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveToTote: public CommandBase
{
public:
	MoveToTote();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
