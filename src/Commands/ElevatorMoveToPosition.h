#ifndef ElevatorMoveToPosition_H
#define ElevatorMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

class ElevatorMoveToPosition: public CommandBase
{
private:

public:
	ElevatorMoveToPosition(GamePad* joy);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	GamePad* joystick;
	void moveToHeight(int inchesUp);
	int getPresetHeight();
	const float HEIGHT_TOLERANCE = 1.0f;
	bool isManualEngaged;
	bool wasManualEngaged;
	int preset;
};

#endif
