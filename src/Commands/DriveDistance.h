#ifndef DriveDistance_H
#define DriveDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveDistance: public CommandBase
{
private:
	float targetDistanceX; ///<Distance to travel left-right
	float targetDistanceY; ///<Distance to travel forward-back
	float distanceX; ///<Current distance left-right
	float distanceY; ///<Current distance forward-back
	float xRatio; ///< ratio of targetDistanceX and Y (see intializer)
	float yRatio; ///< ratio of targetDistanceY and X

public:
	///Sets up values
	///@param targetDistanceX distance to go left-right
	///@param targetDistanceY distance to go forward-back
	DriveDistance(float targetDistanceX, float targetDistanceY);
	void Initialize(); ///<Calculates ratio to distance to travel (x to y)
	void Execute(); ///<Calculates distance traveled and moves robot
	bool IsFinished(); ///< checks distance to targetDistance
	void End(); ///<stops robot
	void Interrupted(); ///<stops robot
};

#endif
