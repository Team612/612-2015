#include "RoughAlign.h"

RoughAlign::RoughAlign(float d, float b, float dw) //good for autonomous. It aligns itself to the front of the tote. some what accurate.
{
	drivedistance = new DriveDistance(0,0);
	bearingToTote = b;
	distanceToTote = d;
	distanceToBeAway = dw;
}

// Called just before this Command runs the first time
void RoughAlign::Initialize()
{
	//Look at issue #126 to understand
	drivedistance->DriveDistance(0.0f, 0.0f, bearingToTote*-1); //turn left parallel to tote
	drivedistance->DriveDistance(cos(bearingToTote * (3.14159 / 180.0))*distanceToTote, 0.0f, 0.0f); //move sideways to in front of tote
	drivedistance->DriveDistance(0.0f, (sin(bearingToTote * (3.14159 / 180.0))*distanceToTote) - distanceToBeAway, 0.0f); //move to the tote (the distanceToBeAway variable is the distance it will be away from the tote)
	done = true;
}

// Called repeatedly when this Command is scheduled to run
void RoughAlign::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool RoughAlign::IsFinished()
{
	return done;
}

// Called once after isFinished returns true
void RoughAlign::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RoughAlign::Interrupted()
{

}
