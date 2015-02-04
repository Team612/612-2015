#include "CommandBase.h"
#include "RobotMap.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI* CommandBase::oi = NULL;
Elevator* CommandBase::elevator = NULL;
MecanumDrivetrain* CommandBase::drivetrain = NULL;
Vision* CommandBase::vision = NULL;
Gyroscope* CommandBase::gyroscope = NULL;
DriveEncoder* CommandBase::encoder = NULL;
DriveAccelerometer* CommandBase::accelerometer = NULL;
Ultrasonic612* CommandBase::ultrasonic612 = NULL;


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
	elevator = new Elevator();
	drivetrain = new MecanumDrivetrain(MOTOR_LR, MOTOR_LF, MOTOR_RR, MOTOR_RF);
	gyroscope = new Gyroscope();
	encoder = new DriveEncoder();
	accelerometer = new DriveAccelerometer();
	ultrasonic612 = new Ultrasonic612();
}
