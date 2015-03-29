
#include "DriveDistance.h"
#include "../Subsystems/PixelLogic.h"


DriveDistance::DriveDistance(float targetDistanceX, float targetDistanceY)
{
	Requires(drivetrain);
	distanceX = 0;
	distanceY = 0;
	xRatio = targetDistanceX/targetDistanceY;
	yRatio = targetDistanceY/targetDistanceX;
	if(xRatio > 0 && targetDistanceX < 0)
	{
		xRatio *= -1;
	}
	if(yRatio > 0 && targetDistanceY < 0)
	{
		yRatio *= -1;
	}
	if(xRatio > 1 || xRatio < -1)
	{
		xRatio *= yRatio;
		yRatio *= yRatio;
	}
	if(yRatio > 1 || yRatio < -1)
	{
		yRatio *= xRatio;
		xRatio *= xRatio;
	}
	std::printf("Constructor called\n");
}

// Called just before this Command runs the first time
void DriveDistance::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute()
{
	distanceX = (drivetrain->getDistance(Drivetrain::MotorLocation::RIGHT_FRONT)*1+drivetrain->getDistance(Drivetrain::MotorLocation::RIGHT_REAR)+drivetrain->getDistance(Drivetrain::MotorLocation::LEFT_FRONT)+drivetrain->getDistance(Drivetrain::MotorLocation::LEFT_REAR)*-1)/4;
	distanceY = (drivetrain->getDistance(Drivetrain::MotorLocation::RIGHT_FRONT)+drivetrain->getDistance(Drivetrain::MotorLocation::RIGHT_REAR)+drivetrain->getDistance(Drivetrain::MotorLocation::LEFT_FRONT)*-1+drivetrain->getDistance(Drivetrain::MotorLocation::LEFT_REAR)*-1)/4;
	drivetrain->move(xRatio, yRatio, 0.0f);
	static int count = 0;
	if (count % 60 == 0)
	{
		std::printf("Execute called\n");
		count++;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished()
{
	if(((distanceX >= targetDistanceX && targetDistanceX > 0) || (distanceX <= targetDistanceX && targetDistanceX < 0)) &&
	   ((distanceY >= targetDistanceY && targetDistanceY > 0) || (distanceY <= targetDistanceY && targetDistanceY < 0)))
	{
		drivetrain->stop();
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void DriveDistance::End()
{
	std::printf("Ending command\n");
	drivetrain->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted()
{
	std::printf("Interrupted\n");
	drivetrain->stop();
}

/*void DriveDistance::DrivetoTote(bool isAtTargetDistance)
{
	if(isAtTargetDistance == false)
	{
		drivetrain->move(0.0f, 0.4f, 0.0);
		PixelLogic->isAtTargetDistance(int leftBoundHeight, int rightBoundHeight, const int targetBoundHeight);
	} else {
		drivetrain->stop();
	}
}
*/
