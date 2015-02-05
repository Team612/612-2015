#include "AverageDistance.h"

double left_measurement;
double right_measurement;

AverageDistance::AverageDistance()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(ultrasonic612);
}

// Called just before this Command runs the first time
void AverageDistance::Initialize()
{
	left_measurement = ultrasonic612->measureL();
	right_measurement = ultrasonic612->measureR();
	//AverageDistance::isDone = false;
}

// Called repeatedly when this Command is scheduled to run
void AverageDistance::Execute()
{
	left_measurement = ultrasonic612->measureL();
	right_measurement = ultrasonic612->measureR();
	double average = (left_measurement + right_measurement)/2;
	SmartDashboard::PutNumber("Average of Ultrasonic measurements:", average);
	AverageDistance::isADDone = true;
}

// Make this return true when this Command no longer needs to run execute()
bool AverageDistance::IsFinished()
{
	return isADDone;
}

// Called once after isFinished returns true
void AverageDistance::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AverageDistance::Interrupted()
{

}
