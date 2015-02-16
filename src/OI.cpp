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
	driver = new GamePad(DRIVER_JOY);
	gunner = new GamePad(GUNNER_JOY);

	gunner->ButtonX->WhenPressed(new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kForward));
	gunner->ButtonY->WhenPressed(new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kReverse));
	gunner->ButtonB->WhileHeld(new ElevatorUp());
	gunner->ButtonA->WhileHeld(new ElevatorDown());
}
