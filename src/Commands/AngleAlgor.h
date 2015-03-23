#ifndef AngleAlgor_H
#define AngleAlgor_H

#include "WPILib.h"
#include <cmath>

//all ratios are width/height
const float toteLength = 26.9;
const float toteWidth = 16.9;
const float toteHeight = 12.1;
const float toteDiagonal = 31.76;
const float shortFaceRatio = toteWidth/toteHeight;
const float longFaceRatio = toteLength/toteHeight;
const float maxFaceRatio = toteDiagonal/toteHeight;
const double maxRatioAngle = 58.2;
float ratioRight = 0;
float ratioLeft = 0;
double ratioAverage = 0;
int leftOrRight = 0; //indicates whether you are left or right of max angle; right is 1, left is -1
float angle = 0;
double AngleAlgor(float wR, float hR, float wL,  float hL); //feed algor the dinosaur


#endif
