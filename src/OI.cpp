#include "OI.h"
#include "Commands/Latch.h"
#include "Commands/ElevatorUp.h"
#include "Commands/ElevatorDown.h"
#include <DoubleSolenoid.h>
#include "Commands/ElevatorStop.h"
#include "Commands/ElevatorMove.h"
#include "RobotMap.h"

GamePad* OI::driver = NULL; ///< Sets driver to null
GamePad* OI::gunner = NULL; ///< Sets gunner to null

OI::OI()
{
	toggleOpen = true; //<false is closed, true is opened

	printf("OIinit0\n");
	driver = new GamePad(true, DRIVER_JOY); ///<Sets driver to real value
	printf("OIinit1\n");
	gunner = new GamePad(false, GUNNER_JOY); ///< Sets gunner to real value
	printf("OIinit2\n");
	/*gunner->ButtonX->WhenPressed(new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kForward));
	printf("OIinit3\n");
	gunner->ButtonY->WhenPressed(new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kReverse));
	printf("OIinit4\n");
	gunner->ButtonB->WhileHeld(new ElevatorUp());
	printf("OIinit5\n");
	gunner->ButtonA->WhileHeld(new ElevatorDown());
	printf("OIinit6\n");*/
	ElevatorMove* elevatormove = new ElevatorMove(gunner);
	elevatormove->Start();
	isLatchPressed = false;
	wasLatchPressed = false;
	toggleOpen = true;
	Latch* open = new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kReverse);
	open->Start();
}

//You better be thankful drive team -_-
void OI::handleLatch()
{
	isLatchPressed = gunner->GetButtonStateA();
	if(isLatchPressed && !wasLatchPressed)
	{
		if(toggleOpen) //if the latch is open
		{
			Latch* close = new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kForward); //Close the latch
			std::printf("Latch close(oi)\n");
			close->Start();
			toggleOpen = false;
		}
		else //if the latch is closed
		{
			Latch* open = new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kReverse); //open the latch
			std::printf("Latch open(oi)\n");
			open->Start();
			toggleOpen = true;
		}
	}
	wasLatchPressed = isLatchPressed;
}

void OI::handleElevator()
{
	//move Elevator Up
	/*val = gunner->GetRightYSmooth();
	if(val > 0.1f && hasDriven == false)
	{
		hasDriven = true;
		elevatorC = new ElevatorUp();
		std::printf("Elev up(oi)\n");
		elevatorC->Start();
	}

	//Move Elevator Down
	else if(val < -0.1f && hasDriven == false)
	{
		hasDriven = true;
		elevatorC = new ElevatorDown();
		std::printf("Elev down(oi)\n");
		elevatorC->Start();
	}
	else
	{
		elevatorC = new ElevatorStop();
		elevatorC->Start();
		hasDriven = false;
	}
	preval = val;*/
}
