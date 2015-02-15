#include <Commands/Latch.h>

/** Called just before this Command runs the first time
 * This is run after the constructor.  The initialization code could be done here, too.
 * In many cases, this method is no different than the constructor, so adding code here
 * is not always necessary.
 */
Latch::Latch(bool latchState)
{
	timer = new Timer();
	solenoid = new DoubleSolenoid(SOLENOIDCHAN1, SOLENOIDCHAN2);
	if (latchState)
	{
		openClose = Open;
	}
	else
	{
		openClose = Close;
	}
}

void Latch::Initialize()
{
	timer->Start();
	if(openClose == Open)
	{
		solenoid->Set(DoubleSolenoid::Value::kForward);
	}
	else
	{
		solenoid->Set(DoubleSolenoid::Value::kReverse);
	}
}

void Latch::Execute()
{

}

bool Latch::IsFinished()
{
	return true;
}

// clean-up method
void Latch::End()
{
	if(timer->Get() >= 1.0)
	{
		solenoid->Set(DoubleSolenoid::Value::kOff);
	}
	else
	{
		End();
	}
}

void Latch::Interrupted()
{
	solenoid->Set(DoubleSolenoid::Value::kOff);
}
