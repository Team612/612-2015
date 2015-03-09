#include "OI.h"
#include "Commands/Latch.h"
#include <DoubleSolenoid.h>
#include "Commands/ElevatorMove.h"
#include "RobotMap.h"

Lib612::GamePad* OI::driver = Lib612::driver;
Lib612::GamePad* OI::gunner = Lib612::gunner;

OI::OI()
{
	toggleOpen = true; //false is closed, true is opened

	printf("OIinit0\n");
	//driver = new GamePad(DRIVER_JOY);Move IMU, Datalogging, and GamePad to Lib612
	printf("OIinit1\n");
	//gunner = new GamePad(GUNNER_JOY);
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
	static bool latchToggle = true;
	const bool OPEN = true, CLOSE = false;

	isLatchPressed = gunner->GetRawButton(BUTTON_RB);

	if(isLatchPressed && !wasLatchPressed)
	{
		int solenoidPos;
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
		if()
		command = new Latch(CommandBase::elevator->getSolenoid(), solenoidPos);
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
