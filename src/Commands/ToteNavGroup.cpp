#include "../Commands/LatchEngage.h"
#include "CommandBase.h"
#include "MoveToTote.h"
#include "LatchEngage.h"
#include "ToteNavGroup.h"

ToteNavGroup::ToteNavGroup() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these Commandswill run in order.

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
	//Requires(CommandBase::vision);
	AddSequential(new MoveToTote());
	AddSequential(new LatchEngage(false)); // Ensure that latch is open before grabbing tote
	AddSequential(new LatchEngage(true));
}
