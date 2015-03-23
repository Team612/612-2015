#include "PixelLogic.h"
#include "../RobotMap.h"
#include "../Commands/DriveDistance.h"


PixelLogic::PixelLogic() :
		Subsystem("Vision")
{
	i2c = new I2C(I2C::kOnboard, 2);
}

void PixelLogic::InitDefaultCommand()
{

}

void PixelLogic::I2CRecieve()
{
	//learn to convert bytes to ints OR just set them = and hope for the best
	//find a way to guarrentee this is only called once a tick
	//god I am tired

	uint8_t buffer[7];
	buffer[0] = 0;
	i2c->ReadOnly(7, buffer);

	printf("pi2c cra[\n");

	if(buffer[0] == 0)
	{
		int widthLeft = buffer[1];
		std::printf("widthLeft has been set to %d \n", widthLeft);
		int heightLeft = buffer[2];
		std::printf("widthLeft has been set to %d \n", heightLeft);
		int leftLowerBound = buffer[3];
		std::printf("leftLowerBound has been set to %d \n", leftLowerBound);
		int leftUpperBound = leftLowerBound + widthLeft;
		std::printf("leftUpperBound has been set to %d \n", leftUpperBound);
		tick++;
		//do I even need to wait a tick?
		//if I have Autonomous call I2C receive, then only *this* will run until buffer[0] does actually say 1
	}
	if(tick%2 == 0 && buffer[0] == 1)
	{
		int widthright = buffer[1];
		std::printf("widthRight has been set to %d \n", widthRight);
		int heightright = buffer[2];
		std::printf("heightRight has been set to %d \n", heightRight);
		int rightLowerBound = buffer[3];
		std::printf("rightLowerBound has been set to %d \n", rightLowerBound);
		int rightUpperBound = rightLowerBound + widthRight;
		std::printf("rightUpperBound has been set to %d \n", rightUpperBound);

		IsTargetDistance(leftBoundHeight, rightBoundHeight, targetBoundHeight);

	}
	if (buffer[0] == 2 || buffer[0] == 3)
	{
		std::printf("I saw nothing! Kajeet did nothing!\n");
	}
}

void PixelLogic::IsTargetDistance(int leftBoundHeight, int rightBoundHeight, int targetBoundHeight)
{
	if(leftBoundHeight-rightBoundHeight <= 6 && leftBoundHeight-targetBoundHeight <= 6)
	{
		IsAtTargetDistance = true;
		//run ultrasonic/ir autoalign
	}
	else
	{
		//drivedistance->DrivetoTote(bool isAtTargetDistance);
	}
}
//Should TECHNICALLY be a command (it even has a stop function) but whatever


/*void PixelLogic::boundWidth(leftLowerBound, leftUpperBound, rightLowerBound, rightUpperBound)
{
	leftUpperBound-leftLowerBound = int leftBoundWidth;
	rightUpperBound-rightLowerBound = int rightBoundWidth;
	int leftBoundWidth-int rightBoundWidth = int boundDifference;
}



void PixelLogic::robotIsAligned(boundDifference, boundTolerance, leftLowerBound, rightUpperBound)
{
	if(boundDifference < boundTolerance && leftLowerBound > 150 && rightUpperBound < 150)
	{
		robotIsAligned = true;
	} else {
		robotIsAligned = false;
	}

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
*/
