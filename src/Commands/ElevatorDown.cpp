#include "ElevatorDown.h"

ElevatorDown::ElevatorDown()
{
	Requires(elevator);
	std::printf("Elevator Down contructor\n");
}

// Called just before this Command runs the first time
void ElevatorDown::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ElevatorDown::Execute()
{
	elevator->move(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorDown::IsFinished()
{
	std::printf("ElevatorDown::IsFinished\n");
	return false;
}

// Called once after isFinished returns true
void ElevatorDown::End()
{
	elevator->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorDown::Interrupted()
{
	elevator->stop();
	std::printf("ElevatorDown::Interrupted\n");
}
