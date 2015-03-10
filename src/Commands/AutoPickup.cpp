/* TODO:
 *
 *  Move the forks to the correct height
 *  Align with crates (this may require to move a bit forward or back and fire the solenoid then move up a bit
 *  Put a crate down on a stack then pick them up
 *  Put crate down, rotate around the stack (later will push forward into auto zone)
 */

#include "CommandBase.h"
#include "AutoPickup.h"

// Command inclusions
#include "AutoAlign.h"
#include "ElevatorMoveToPosition.h"

// Hash-defines for easy change of values during testing
#define LOWERMOST_TOTE_HEIGHT 0
#define SECOND_TOTE_HEIGHT 10

AutoPickupGroup::AutoPickupGroup()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these Commands will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	Requires(CommandBase::drivetrain);
	Requires(CommandBase::vision);

	AddSequential(new AutoAlign());

	// Stack totes
	AddSequential(new ElevatorMoveToPosition(SECOND_TOTE_HEIGHT));
	AddSequential(new MoveToTote());
	AddSequential(new Latch(CommandBase::elevator->getSolenoid(), Latch::OPEN));
	AddSequential(new ElevatorMoveToPosition(LOWERMOST_TOTE_HEIGHT))
}
