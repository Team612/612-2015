#ifndef AngleAlgor_H
#define AngleAlgor_H

#include "WPILib.h"
#include <cmath>

//all ratios are width/height
const float toteLength = 26.9; ///< length of tote (inches)
const float toteWidth = 16.9; ///< width of tote (inches)
const float toteHeight = 12.1; ///< height of tote (inches)
const float toteDiagonal = 31.76; ///< length of diagonal of tote (inches)
const float shortFaceRatio = toteWidth/toteHeight; ///< ratio of width to height
const float longFaceRatio = toteLength/toteHeight; ///<ratio of length to height
const float maxFaceRatio = toteDiagonal/toteHeight; ///< ratio of diag to height (biggest ratio possible)
const double maxRatioAngle = 58.2; ///<Value returned if above ratio is used
float ratioRight = 0; ///< ratio value if we're to the right of tote
float ratioLeft = 0; ///< ratio value if we're to the left of tote
double ratioAverage = 0; ///< Average ratio
int leftOrRight = 0; ///<indicates whether you are left or right of max angle; right is 1, left is -1
float angle = 0; ///<Angle in relation to tote
///Constructor
///Not sure what the parameters are for/how to calculate them, need to ask Shaun
double AngleAlgor(float wR, float hR, float wL,  float hL);


#endif
