#include "BreakerFlipper.h"

BreakerFlipper::BreakerFlipper()
{
	timer = new Timer();
	encoder = new Encoder(encoderChannelA, encoderChannelB);
	powerboard = new PowerBoard();
	talonsrx = new TalonSRX(channelCheck);
}

// Called just before this Command runs the first time
void BreakerFlipper::Initialize()
{
	previousAmp = powerboard->GetCurrent(channelCheck);
}

void BreakerFlipper::CheckMotor()
{
	if (encoder->GetRaw() <= 0 && timer->Get() > timeLimit)
	{
		talonsrx->Set(0.0);
	}
	else if (timer->Get() < timeLimit)
	{
		CheckMotor();
	}
}
// Called repeatedly when this Command is scheduled to run
void BreakerFlipper::Execute()
{
	if(previousAmp - powerboard->GetCurrent(channelCheck) < ampLimit)
	{
		timer->Reset();
		timer->Start();
		CheckMotor();
	}
	previousAmp = powerboard->GetCurrent(channelCheck);
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
