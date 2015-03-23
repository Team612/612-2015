#ifndef DriveDistance_H
#define DriveDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveDistance: public CommandBase
{
private:
	float targetDistanceX;
	float targetDistanceY;
	float distanceX;
	float distanceY;
	float xRatio;
	float yRatio;

public:
	DriveDistance(float targetDistanceX, float targetDistanceY);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void DrivetoTote(bool isAtTargetDistance);
};

#endif
