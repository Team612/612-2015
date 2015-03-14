#include "AngleAlgor.h"

double AngleAlgor(float wR, float hR, float wL,  float hL)
{
	ratioRight = wR/hR;
	ratioLeft = wL/wL;
	ratioAverage = (ratioRight + ratioLeft)/2;
	if(ratioRight > ratioLeft) //Means right side is closer to max angle; that side is closer to the robot
	{
		leftOrRight = -1;
	}
	else if(ratioLeft > ratioRight)
	{
		leftOrRight = 1;
	}
	else //They're the same (improbable but possible)
	{
		leftOrRight = 0;
		return maxRatioAngle;
	}

	if(leftOrRight == 1) //Right side closer
	{
		return ( 0.0243029 + sqrt( ( -0.0243029 * -0.0243029 ) - ( 4 * 0.000111078 * (2.66466 - ratioAverage) ) ) ) / 2*0.000111078;
		//Line of best fit for the graph that returns the angle (fairly accurate)
	}
	else if(leftOrRight == -1)
	{
		return ( 0.00023557 + sqrt( ( -0.00023557 * -0.00023557 ) - ( 4 * 0.0000465902 * (2.2209 - ratioAverage) ) ) ) / 2*0.0000465902;
	}
}
