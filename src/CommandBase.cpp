#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"
#include "Subsystems/MecanumDrivetrain.h"
#include "RobotMap.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI* CommandBase::oi = NULL;
MecanumDrivetrain* CommandBase::drivetrain = NULL;

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
	examplesubsystem = new ExampleSubsystem();
	oi = new OI();
	drivetrain = new MecanumDrivetrain(MOTOR_LR, MOTOR_LF, MOTOR_RR, MOTOR_RF);
}
