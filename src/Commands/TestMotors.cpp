#include "TestMotors.h"

TestMotors::TestMotors()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	isTestDone = false;

	testMotorTimer = new Timer();

	//MecanumDrivetrain* drive = new MecanumDrivetrain(TALON1_CHANNEL, TALON2_CHANNEL, TALON3_CHANNEL, TALON4_CHANNEL);

	Requires(drive);
}

// Called just before this Command runs the first time
void TestMotors::Initialize()
{
	testMotorTimer->Start();
}

// Called repeatedly when this Command is scheduled to run
void TestMotors::Execute()
{
	if(!testMotorTimer->HasPeriodPassed(10.0))
	{
		drive->move(0.5, 0.0, 0.0);
	}
	else
	{
		drive->stop();
		isTestDone = true;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool TestMotors::IsFinished()
{
	return isTestDone;
}

// Called once after isFinished returns true
void TestMotors::End()
{
	testMotorTimer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TestMotors::Interrupted()
{
	drive->stop();
	testMotorTimer->Stop();
}
