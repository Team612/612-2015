#include "AngleAlgor.h"

float AngleAlgor::AngleAlgor(float wR, float hR, float wL,  float hL)
{
	ratioRight = wR/hR;
	ratioLeft = wL/wL;
	ratioAverage = (ratioRight + ratioLeft)/2;
	if(ratioRight > ratioLeft)
	{
		leftOrRight = -1;
	}
	else if(ratioLeft > ratioRight)
	{
		leftOrRight = 1;
	}
	else
	{
		leftOrRight = 0;
		return maxRatioAngle;
	}

	if(leftOrRight == 1)
	{
		return 90*((ratioAverage - shortFaceRatio)/shortFaceRange);
	}
	else if(leftOrRight == -1)
	{
		return (90*((ratioAverage - longFaceRatio)/longFaceRange))+90;
	}
}

/* Called just before this Command runs the first time
void AngleAlgor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AngleAlgor::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AngleAlgor::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AngleAlgor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AngleAlgor::Interrupted()
{

}
*/
