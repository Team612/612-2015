#ifndef LatchClose_H
#define LatchClose_H

#include "../CommandBase.h"
#include "WPILib.h"

class LatchClose: public CommandBase
{
public:
	LatchClose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
