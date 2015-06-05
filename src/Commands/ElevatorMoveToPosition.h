#ifndef ElevatorMoveToPosition_H
#define ElevatorMoveToPosition_Ht

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

class ElevatorMoveToPosition: public CommandBase
{
private:

public:
	/// Moves elevator to spot
	///@param joy joystick object
	///@param presetSpeed how fast to move elevator
	ElevatorMoveToPosition(GamePad* joy, float presetSpeed);
	ElevatorMoveToPosition(int presetMove, float presetSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	GamePad* joystick;
	void moveToHeight(float inchesUp);
	int getPreset();
	const float HEIGHT_TOLERANCE = 1.0f;
	bool isManualEngaged;
	bool wasManualEngaged;
	bool isLB;
	bool wasLB;
	bool isRB;
	bool wasRB;
	bool isDynamic;
	float speed;
	int preset;
};

#endif