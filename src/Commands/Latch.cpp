#include <Commands/Latch.h>
#include "RobotMap.h"

/** Called just before this Command runs the first time
 * This is run after the constructor.  The initialization code could be done here, too.
 * In many cases, this method is no different than the constructor, so adding code here
 * is not always necessary.
 */
Latch::Latch()
{
	timer = new Timer();
	solenoid = new DoubleSolenoid(SOLENOIDCHAN1, SOLENOIDCHAN2);
}

void Latch::Initialize()
{
	timer->Start();
	solenoid->Set(DoubleSolenoid::Value::kReverse);
}

void Latch::Execute()
{
	// if(timer->Get() >= 1.0)
		// solenoid->Set(DoubleSolenoid::Value::kReverse);
}

bool Latch::IsFinished()
{
	return (timer->Get() >= TIMER_VALUE);
}

// clean-up method
void Latch::End()
{
	timer->Reset();
	solenoid->Set(DoubleSolenoid::Value::kOff);
}

void Latch::Interrupted()
{
	solenoid->Set(DoubleSolenoid::Value::kOff);
}
