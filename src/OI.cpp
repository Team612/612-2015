#include "OI.h"
#include "Commands/Latch.h"
#include "Commands/ElevatorUp.h"
#include "Commands/ElevatorDown.h"
#include <DoubleSolenoid.h>
#include "Commands/ElevatorStop.h"

GamePad* OI::driver = NULL;
GamePad* OI::gunner = NULL;

OI::OI()
{
	toggleOpen = true; //false is closed, true is opened

	printf("OIinit0\n");
	driver = new GamePad(DRIVER_JOY);
	printf("OIinit1\n");
	gunner = new GamePad(GUNNER_JOY);
	printf("OIinit2\n");
	/*gunner->ButtonX->WhenPressed(new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kForward));
	printf("OIinit3\n");
	gunner->ButtonY->WhenPressed(new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kReverse));
	printf("OIinit4\n");
	gunner->ButtonB->WhileHeld(new ElevatorUp());
	printf("OIinit5\n");
	gunner->ButtonA->WhileHeld(new ElevatorDown());
	printf("OIinit6\n");*/
}

//You better be thankful drive team -_-
void OI::handleLatch()
{
	if(gunner->GetRawButton(6))
	{
		if(toggleOpen) //if the latch is open
		{
			Latch* close = new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kForward); //Close the latch
			printf("Latch close");
			close->Start();
			toggleOpen = !toggleOpen;
		}
		else //if the latch is closed
		{
			Latch* open = new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kReverse); //open the latch
			printf("Latch open");
			open->Start();
			toggleOpen = !toggleOpen;
		}
	}
}

void OI::handleElevator()
{
	//move Elevator Up
	val = gunner->GetRightYSmooth();
	if(val > 0.1f)
	{
		hasDriven = true;
		ElevatorUp* up = new ElevatorUp();
		printf("Elev up");
		up->Start();
		std::printf("We should be moving up now\n");
	}

	//Move Elevator Down
	else if(val < 0.1f)
	{
		hasDriven = true;
		ElevatorDown* down = new ElevatorDown();
		printf("Elev down");
		down->Start();
	}
	else
	{
		ElevatorStop* stop = new ElevatorStop();
		hasDriven = false;
	}
	preval = val;
}
