#include "CommandBase.h"
#include "RobotMap.h"

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
Elevator* CommandBase::elevator = NULL;
Drivetrain* CommandBase::drivetrain = NULL;
Vision* CommandBase::vision = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	oi = new OI();
	elevator = new Elevator();
	drivetrain = new Drivetrain(MOTOR_LR, MOTOR_LF, MOTOR_RR, MOTOR_RF, INFRARED);
}
