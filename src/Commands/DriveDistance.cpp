#include <Commands/DriveDistance.h>
#include <math.h>

DriveDistance::DriveDistance(float rotationsX, float rotationsY)
{
	Requires(drivetrain);
	targetDistanceX = rotationsX * (90/(8*3.14159));
	targetDistanceY = rotationsY * (90/(8*3.14159));
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
	drivetrain->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute()
{
	distanceX = drivetrain->getDistance(Drivetrain::MotorLocation::RIGHT_FRONT);
	distanceY = drivetrain->getDistance(Drivetrain::MotorLocation::RIGHT_FRONT);
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
