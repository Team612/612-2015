#ifndef Latch_H
#define Latch_H

#include "../CommandBase.h"
#include "WPILib.h"

class Latch: public CommandBase
{
public:
	Latch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* EXAMPLE_COMMAND_H */
