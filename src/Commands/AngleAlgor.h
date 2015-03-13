#ifndef AngleAlgor_H
#define AngleAlgor_H

#include "WPILib.h"

class AngleAlgor
{
private:
	//all ratios are width/height
	const float toteLength = 26.9;
	const float toteWidth = 16.9;
	const float toteHeight = 12.1;
	const float toteDiagonal = 31.76;
	const float shortFaceRatio = toteWidth/toteHeight;
	const float longFaceRatio = toteLength/toteHeight;
	const float maxFaceRatio = toteDiagonal/toteHeight;
	const float maxRatioAngle = 58.2;
	const float shortFaceRange = maxFaceRatio - shortFaceRatio;
	const float longFaceRange = maxFaceRatio - shortFaceRatio;
	float ratioRight = 0;
	float ratioLeft = 0;
	float ratioAverage = 0;
	int leftOrRight = 0; //indicates whether you are left or right of max angle right is 1, left is -1
public:
	float angle = 0;
	float AngleAlgor(float wR, float hR, float wL,  float hL); //feed algor the dinosaur
	/*
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	*/
};

#endif
