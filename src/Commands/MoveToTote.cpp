#include "MoveToTote.h"

/** The constructor of the Command might initialize any class variables pertinent to the Command.
 * Good examples of these variables might be a loop count, a timer.  Variables for robot
 * hardware, such as a motor controller, etc. should not be created here (but in a Subsystem).
 */
MoveToTote::MoveToTote()
{
	Requires(drivetrain);
	Requires(vision);
}

void MoveToTote::Initialize()
{

}

void MoveToTote::Execute()
{
	static int count = 0;
	count++;

	vision->receiveI2C();

	vision->printCameraStatistics(Vision::LEFT);
	vision->printCameraStatistics(Vision::RIGHT);

	//Can only do it every 1/30th of a second because of I2C stuffs
	if (count == 2 && (vision->hasReceived(Vision::LEFT) && vision->hasReceived(Vision::RIGHT)))
	{
		navigate();
		count = 0;
	}
}

bool MoveToTote::IsFinished()
{
	return success;
}

void MoveToTote::End()
{
	drivetrain->stop();
}

void MoveToTote::Interrupted()
{
	drivetrain->stop();
}

void MoveToTote::navigate()
{
	if ()
}
