#ifndef PixelLogic_H
#define PixelLogic_H

#include "Vision.h"
#include "WPILib.h"
//#include "../CommandBase.h"
#include <I2C.h>

class PixelLogic: public Subsystem
{
private:
	int tick = 0;
	//DriveDistance* drivedistance = new DriveDistance(10.0f, 10.0f);
	I2C* i2c;

public:
	int widthLeft;
	//width in pixels from left camera
	int widthRight;
	//width in pixels from right camera
	int heightLeft;
	//height in pixels from left camera
	int heightRight;
	//height in pixels from right camera
	int leftLowerBound;
	//is passed as #3 in the byte array
	int leftUpperBound;
	//is equal to leftLowerBound+widthLeft
	int rightLowerBound;
	//is #3 in the array
	int rightUpperBound;
	//is rightLowerBound+widthRight

	int leftBoundHeight;
	int leftBoundLength;
	//for the left camera

	int rightBoundHeight;
	int rightBoundLength;
	//for the right camera

	int pixelOverlapLower;
	int pixelOverlapUpper;
	int pixelOverlapWidth;
	int boundDifference;
	//what both cameras see and the width of that area

	const int targetBoundHeight = 23;
	const int boundTolerance = 6;
	//if the pixie cams can get overlap between the lower and upper bounds, we are aligned
	//TODO get actual values, replace these placeholders

	bool IsAtTargetDistance = false;
	bool robotIsAligned = false;
	//self explanatory, isAtTargetDistance is set and used by DriveDistance::DriveToTote
	PixelLogic();
	void boundWidth(int leftLowerBound, int leftUpperBound, int rightLowerBound, const int rightUpperBound);
	void isAligned(int leftBoundLength, int rightBoundLength);
	void InitDefaultCommand();
	void I2CRecieve();
	void IsTargetDistance(int leftBoundHeight, int rightBoundHeight, int targetBoundHeight = 80);
	void PixelOverlap(int leftLowerBound, int leftUpperBound, int rightLowerBound, int rightUpperBound);
	void PixelStop();
};

#endif
