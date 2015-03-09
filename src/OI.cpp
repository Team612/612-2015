#include "OI.h"
#include "Commands/Latch.h"
#include <DoubleSolenoid.h>
#include "Commands/ElevatorMove.h"
#include "RobotMap.h"

GamePad* OI::driver = NULL;
GamePad* OI::gunner = NULL;

OI::OI()
{
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
	ElevatorMove* elevatormove = new ElevatorMove(gunner);
	elevatormove->Start();
	/*
	 * isLatchPressed = false;
	 * toggleOpen = true;
	 */
	Latch* open = new Latch(CommandBase::elevator->getSolenoid(), DoubleSolenoid::kReverse);
	open->Start();
}

void OI::handleLatch()
{
	static Latch* command;
	static bool isLatchPressed = false;
	static bool wasLatchPressed = false;
	const bool OPEN = true;//, CLOSE = false;

	isLatchPressed = gunner->GetRawButton(BUTTON_RB);

	if(isLatchPressed && !wasLatchPressed)
	{
		/*
		* if(latchToggle == OPEN) //if the latch is open
		* {
		*	solenoidPos = DoubleSolenoid::kForward; //Close the latch
		*	std::printf("Latch close (OI)\n");
		*	toggleOpen = CLOSE;
		* }
		* else //if the latch is closed
		* {int solenoidPos;
		*	solenoidPos = DoubleSolenoid::kReverse; //open the latch
		*	std::printf("Latch open (OI)\n");
		*	toggleOpen = OPEN;
		* }
		*/
		DoubleSolenoid::Value solenoidState = command->state == OPEN ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse;
		command = new Latch(CommandBase::elevator->getSolenoid(), solenoidState);
		command->Start();
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
