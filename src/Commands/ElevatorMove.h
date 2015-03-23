#ifndef ElevatorMove_H
#define ElevatorMove_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "GamePad.h"

class ElevatorMove: public CommandBase
{
public:
	ElevatorMove(GamePad* joy);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	GamePad* joystick;
};

#endif
