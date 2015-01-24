#ifndef Move_H
#define Move_H

#include "../CommandBase.h"
#include "WPILib.h"
#include <Joystick.h>

class Move: public CommandBase
{
public:
	Move();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	Joystick* driverJoy;
};

#endif
