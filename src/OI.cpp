#include "OI.h"
#include "RobotMap.h"
#include "CommandBase.h"
#include "Commands/ElevatorUp.h"
#include "Commands/ElevatorDown.h"
#include "Commands/Drive.h"
#include "Commands/Latch.h"
#include <DoubleSolenoid.h>

GamePad* OI::driver = NULL;
GamePad* OI::gunner = NULL;

OI::OI()
{
	printf("OIinit0\n");
	driver = new GamePad(DRIVER_JOY);
	printf("OIinit1\n");
	gunner = new GamePad(GUNNER_JOY);
	printf("OIinit2\n");
	gunner->ButtonX->WhenPressed(new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kForward));
	printf("OIinit3\n");
	gunner->ButtonY->WhenPressed(new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kReverse));
	printf("OIinit4\n");
	gunner->ButtonB->WhileHeld(new ElevatorUp());
	printf("OIinit5\n");
	gunner->ButtonA->WhileHeld(new ElevatorDown());
	printf("OIinit6\n");
}
