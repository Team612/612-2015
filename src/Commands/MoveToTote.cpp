#include "MoveToTote.h"

/** The constructor of the Command might initialize any class variables pertinent to the Command.
 * Good examples of these variables might be a loop count, a timer.  Variables for robot
 * hardware, such as a motor controller, etc. should not be created here (but in a Subsystem).
 */
MoveToTote::MoveToTote(uint32_t targetDistance)
{
	Requires(drivetrain);
	Requires(vision);

	targetDist = targetDistance;
}

void MoveToTote::Initialize()
{

}

void MoveToTote::Execute()
{
	static int count = 0;
	count++;

	vision->receiveI2C();

	//Can only do it every 1/30th of a second because of I2C stuffs
	if (count % 2 == 0)
	{
		if (dataAccurate())
		{
			navigate();
		}
	}

	if (count % 30 == 0) {
		vision->printCameraStatistics(Vision::LEFT);
		vision->printCameraStatistics(Vision::RIGHT);
		count = 0;
	}
}

bool MoveToTote::IsFinished()
{
	return success || failure;
}

void MoveToTote::End()
{
	drivetrain->stop();
}

void MoveToTote::Interrupted()
{
	drivetrain->stop();
}

bool MoveToTote::camerasWorking() {
	bool lCamEnabled = vision->hasReceived(Vision::LEFT);
	bool rCamEnabled = vision->hasReceived(Vision::RIGHT);

	return lCamEnabled && rCamEnabled;
}

bool MoveToTote::dataAccurate() {
	//TODO: Also implement this method to detect dramatic changes in data
	static int tolerance = 0;

	if (tolerance > 5)
	{
		failure = true;
		printf("Error: The camera(s) failed to receive 5 times in a row!\nCancelling movement...\nFinal camera statistics:\n");
		vision->printCameraStatistics(Vision::LEFT);
		vision->printCameraStatistics(Vision::RIGHT);
		return false;
	}

	if (camerasWorking())
	{
		tolerance = 0;
		return true;
	}
	else
	{
		printf("Warning: The camera(s) failed to receive, retrying...\n");
		tolerance++;
		return false;
	}
}

void MoveToTote::navigate()
{
	aligned = inRange(vision->getBoundingWidth(Vision::LEFT), vision->getBoundingWidth(Vision::RIGHT), 10);

	//Averages the bounding box heights
	uint32_t average = (vision->getBoundingHeight(Vision::LEFT) + vision->getBoundingHeight(Vision::LEFT)) / 2;
	atTote = inRange(average, targetDist, 2);

	processMovement();
}

float MoveToTote::calculateAlignment()
{
	uint16_t lBounding = vision->getBoundingWidth(Vision::LEFT);
	uint16_t rBounding = vision->getBoundingWidth(Vision::RIGHT);

	if (lBounding > rBounding)
	{
		return -0.8;
	}
	else if (rBounding > lBounding)
	{
		return 0.8;
	}
	else
	{
		return 0.0;
	}
}

void MoveToTote::processMovement()
{
	success = atTote && aligned;

	if (!success && !failure)
	{
		float xMovement = 0;
		float yMovement = 0;

		if (!aligned)
		{
			xMovement = calculateAlignment();
		}
		else
		{
			xMovement = 0;
		}

		if (!atTote)
		{
			yMovement = 0.8;
		}
		else
		{
			yMovement = 0;
		}

		drivetrain->move(xMovement, yMovement, 0);
	}
}

//Checks to see if b is in the range of a by range amount
bool MoveToTote::inRange(int a, int b, uint32_t range)
{
	if (a == b)
	{
		return true;
	}

	int max = a + range;
	int min = a - range;

	return (b < max) && (b > min);
}
