/* TODO:
 *
 *  Move the forks to the correct height
 *  Crates (this may require to move a bit forward or back and fire the solenoid then move up a bit
 *  Put a crate down on a stack then pick them up
 *  Put crate down, rotate around the stack (later will push forward into auto zone)
 */

#include "CommandBase.h"
#include "AutoPickup.h"

// Command inclusions
#include "AutoAlign.h"

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
}
