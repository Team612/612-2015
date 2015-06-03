#ifndef DriveDistance_H
#define DriveDistance_H

#include "../CommandBase.h"
#include "WPILib.h"
#include <cmath>

class DriveDistance: public CommandBase
{
public:
	enum Axis {X_AXIS, Y_AXIS};
	DriveDistance(float distance, float speed, Axis axis = DriveDistance::Y_AXIS); //Apply negative numbers to move the other direction
	//DriveDistance(float xDistance, float yDistance, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float targetDistanceX;
	float targetDistanceY;

	float speed;

	Axis currentAxis = X_AXIS;

	bool xInRange;
	bool yInRange;

	float calculateDistance();

	void checkDistances();
	bool isInRange(float n1, float n2,float range);

};

#endif
