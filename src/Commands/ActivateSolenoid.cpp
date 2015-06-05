#include "ActivateSolenoid.h"

ActivateSolenoid::ActivateSolenoid(DoubleSolenoid* solenoid_, DoubleSolenoid::Value value, uint32_t time)
{
	solenoid = solenoid_;
	timer = new Timer();
	targetTime = time;
	solenoidState = value;
}

// Called just before this Command runs the first time
void ActivateSolenoid::Initialize()
{
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void ActivateSolenoid::Execute()
{
	solenoid->Set(solenoidState);
}

// Make this return true when this Command no longer needs to run execute()
bool ActivateSolenoid::IsFinished()
{
	uint32_t time = timer->Get();
	return time >= targetTime;
}

// Called once after isFinished returns true
void ActivateSolenoid::End()
{
	solenoid->Set(DoubleSolenoid::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActivateSolenoid::Interrupted()
{
	solenoid->Set(DoubleSolenoid::kOff);
}
