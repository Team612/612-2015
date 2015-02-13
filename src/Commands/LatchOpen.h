#ifndef LatchOpen_H
#define LatchOpen_H

#include "../CommandBase.h"
#include "WPILib.h"

class LatchOpen: public CommandBase
{
public:
	LatchOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
