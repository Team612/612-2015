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

/*
DriveDistance::DriveDistance(float xDistance, float yDistance, float speed) {
	 Requires(drivetrain);
	 targetDistanceX = xDistance;
	 targetDistanceY = yDistance;
	 this->speed = speed;
}
*/

DriveDistance::DriveDistance(Axis axis, float distance, float speed)
{
	Requires(drivetrain);
	if (axis == X_AXIS)
	{
		targetDistanceX = distance;
	}
	else if (axis == Y_AXIS)
	{
		targetDistanceY = distance;
	}

	currentAxis = axis;
	this->speed = speed;
}

bool DriveDistance::isInRange(float n1, float n2, float range)
{
	float max = n2 + range;
	float min = n2 - range;

	return n1 <= max && n1 >= min;
}

float DriveDistance::calculateDistance()
{
	float ticks = 0;

	if (currentAxis == X_AXIS)
	{
		ticks = drivetrain->getAverageDistanceX();
	}
	else if (currentAxis == Y_AXIS)
	{
		ticks = drivetrain->getAverageDistanceY();
	}

	return (ticks / TICKS_PER_ROTATION) * WHEEL_CIRCUMFERENCE;
}

void DriveDistance::checkDistances()
{
	float distance = calculateDistance();

	if (isInRange(distance, targetDistanceX, 1))
	{
		xInRange = true;

		if (!yInRange)
		{
			currentAxis = Y_AXIS;
			drivetrain->resetEncoders();
		}
	}

	if (isInRange(distance, targetDistanceY, 1))
	{
		yInRange = true;

		if (!xInRange)
		{
			currentAxis = X_AXIS;
			drivetrain->resetEncoders();
		}
	}
}

// Called just before this Command runs the first time
void DriveDistance::Initialize()
{
	drivetrain->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute()
{

	checkDistances();

	if (currentAxis == X_AXIS)
	{
		drivetrain->move(speed, 0, 0);
	}

	else if (currentAxis == Y_AXIS)
	{
		drivetrain->move(0, speed, 0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished()
{
	return xInRange && yInRange;
}

// Called once after isFinished returns true
void DriveDistance::End()
{
	drivetrain->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted()
{
	drivetrain->stop();
}
