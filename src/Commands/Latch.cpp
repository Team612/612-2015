#include <Commands/Latch.h>

/** Called just before this Command runs the first time
 * This is run after the constructor.  The initialization code could be done here, too.
 * In many cases, this method is no different than the constructor, so adding code here
 * is not always necessary.
 */
void LatchOpen::Initialize()
{
	timer = new Timer();
	firstsolenoid = new DoubleSolenoid(FIRST_SOLENOID);
	secondsolenoid = new DoubleSolenoid(SECOND_SOLENOID);
	firstsolenoid->Set(DoubleSolenoid::Value::kForward);
	secondsolenoid->Set(DoubleSolenoid::Value::kForward);
	timer->Start();
	End();
}

// clean-up method
void LatchOpen::End()
{
	if(timer->Get() >= 1.0)
	{
		firstsolenoid->Set(DoubleSolenoid::Value::kOff);
		firstsolenoid->Set(DoubleSolenoid::Value::kOff);
	}
	else
	{
		End();
	}
}

