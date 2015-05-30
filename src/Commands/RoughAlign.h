#ifndef RoughAlign_H
#define RoughAlign_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "DriveDistance.h"

class RoughAlign: public CommandBase
{
private:
	float distanceToTote; ///< Float for distance to tote
	float bearingToTote; ///< Angle in relation to totte
	float distanceToBeAway; ///< Distance the robot WILL be away (ask Shaun what that means)
	bool done = false; ///< Bool if align is done
public:
	DriveDistance* drivedistance; ///<Drivedistance object
	///approximate allignment
	///@param d distance to tote
	///@param b bearing to tote (angle)
	///@param dw future distance to tote (ASK SHAUN I DUNNO)
	RoughAlign(float d, float b, float dw);
	void Initialize(); ///<Initalizer
	void Execute(); ///< Empty
	bool IsFinished(); ///< Returns true
	void End(); ///<Empty
	void Interrupted(); ///<Empty
};

#endif
