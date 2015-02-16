#include <Commands/DriveDistance.h>
#include <math.h>

DriveDistance::DriveDistance(float rotations)
{
	Requires(drivetrain);
	targetDistance = rotations;
	targetDistance *= 90/(8*3.14159);
	distance = 0;
	std::printf("Constructor called\n");
}

// Called just before this Command runs the first time
void DriveDistance::Initialize()
{
	drivetrain->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute()
{
	distance = abs(drivetrain->getDistance(Drivetrain::MotorLocation::RIGHT_FRONT));
	drivetrain->move(0.0f, 0.8f, 0.0f);
	static int count = 0;
	if (count % 60 == 0)
		std::printf("Execute called\n");
		std::printf("distance: %f\n", distance);
	count++;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished()
{
	static int c = 0;
	bool status = (distance >= targetDistance);
	if (status)
		std::printf("Finished!\n");
	else if (c % 30 == 0)
		std::printf("Not finished!\n");
	c++;
	return status;
}

// Called once after isFinished returns true
void DriveDistance::End()
{
	std::printf("Ending command\n");
	drivetrain->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted()
{
	std::printf("Interrupted\n");
	drivetrain->stop();
}
