#include "Latch.h"
#include "RobotMap.h"

/** Called just before this Command runs the first time
 * This is run after the constructor.  The initialization code could be done here, too.
 * In many cases, this method is no different than the constructor, so adding code here
 * is not always necessary.
 */
Latch::Latch(DoubleSolenoid* sol, DoubleSolenoid::Value val)
{
	commandSol = sol;
	direction = val;
	timer = new Timer();
}

void Latch::Initialize()
{
	timer->Start();
}

void Latch::Execute()
{
	commandSol->Set(direction);
}

bool Latch::IsFinished()
{
	if(timer->Get() >= TIMER_VALUE)
		return true;
	else
		return false;
}

// clean-up method
void Latch::End()
{
	commandSol->Set(DoubleSolenoid::kOff);
}

void Latch::Interrupted()
{
	commandSol->Set(DoubleSolenoid::kOff);
}
