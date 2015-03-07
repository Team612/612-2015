#ifndef ElevatorMove_H
#define ElevatorMove_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Lib612/Lib612.h"

class ElevatorMove: public CommandBase
{
public:
	ElevatorMove(Lib612::GamePad* joy);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Lib612::GamePad* joystick;
};

#endif
