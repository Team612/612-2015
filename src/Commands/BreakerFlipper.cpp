#include "BreakerFlipper.h"

BreakerFlipper::BreakerFlipper()
{
	timer = new Timer();
	encoder = new Encoder(encoderChannelA, encoderChannelB);
	powerboard = new PowerBoard();
}

// Called just before this Command runs the first time
void BreakerFlipper::Initialize()
{

}

void BreakerFlipper::CheckMotor()
{
	if (encoder->GetRaw() <= 0)
	{
		//TODO code here to stop the motor!
	}
}
// Called repeatedly when this Command is scheduled to run
void BreakerFlipper::Execute()
{
	double current = powerboard->GetCurrent(channelCheck);
	if(current > ampLimit)
	{
		CheckMotor();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool BreakerFlipper::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BreakerFlipper::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BreakerFlipper::Interrupted()
{

}
