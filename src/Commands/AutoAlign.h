#ifndef AUTOALIGN_H
#define AUTOALIGN_H

#include "CommandBase.h"
#include "WPILib.h"

class AutoAlign: public CommandBase
{
public:
	AutoAlign();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
