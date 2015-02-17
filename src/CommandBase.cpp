#include "CommandBase.h"
#include "RobotMap.h"
#include <CANTalon.h>

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

	printf("CMDBinit1\n");
	elevator = new Elevator();
	printf("CMDBinit2\n");
	drivetrain = new Drivetrain(new CANTalon(MOTOR_FL), new CANTalon(MOTOR_RL), new CANTalon(MOTOR_FR), new CANTalon(MOTOR_RR), new AnalogInput(INFRARED));
	printf("CMDBinit3\n");
		oi = new OI();
}
