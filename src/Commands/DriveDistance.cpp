#include <Commands/DriveDistance.h>
/*
* This function takes the two distances, and figures out which one is larger
* When that is figured out, it multiplies that ratio by the other ratio.
* The numbers in the ratio cancel out and become 1, and the same thing happens
* To the other ratio. That means the other ratio is a number between 0 and 1
* It was made like this so that you could go at a straight line to where you
* Want to you go based on how the two ratio's compare. This doesn't really work
* Due to problems with encoders.
*/

DriveDistance::DriveDistance(float targetDistanceX, float targetDistanceY)
{
	Requires(drivetrain);
	distanceX = 0;
	distanceY = 0;
	xRatio = targetDistanceX/targetDistanceY;
	yRatio = targetDistanceY/targetDistanceX;
	if(xRatio > 0 && targetDistanceX < 0) //Both targetDistance X and Y are negative
	{
		xRatio *= -1;
	}
	if(yRatio > 0 && targetDistanceY < 0) //Same thing for yRatio
	{
		yRatio *= -1;
	}
	if(xRatio > 1 || xRatio < -1) //You have to go further in x direction than y direction
	{
		xRatio *= yRatio; //xRatio would become exactly +/- 1
		yRatio *= yRatio; //yRatio changes by the same ammount, so it's ratio
	}
	if(yRatio > 1 || yRatio < -1) //You have to go further in the y direction than x
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
