#include "LatchEngage.h"

/** The constructor of the Command might initialize any class variables pertinent to the Command.
 * Good examples of these variables might be a loop count, a timer.  Variables for robot
 * hardware, such as a motor controller, etc. should not be created here (but in a Subsystem).
 */
LatchEngage::LatchEngage(bool engaged)
{
<<<<<<< HEAD:src/Commands/LatchClose.cpp
	Requires(elevator);
=======
	this->engaged = engaged;
>>>>>>> a8fe2b6830f4657d30f0f04aaae386259930804c:src/Commands/LatchEngage.cpp
}

/** Called just before this Command runs the first time
 * This is run after the constructor.  The initialization code could be done here, too.
 * In many cases, this method is no different than the constructor, so adding code here
 * is not always necessary.
 */
void LatchEngage::Initialize()
{

}

/** Called repeatedly when this Command is scheduled to run
 * This method is called many times a second and performs the actions of the Command.
 * Setting a motor value by using a Subsystem method call is an example of what would occur
 * in this method.
 *
 */
void LatchEngage::Execute()
{
	elevator->firstSolClose();
	elevator->secondSolClose();
}

/** Make this return true when this Command no longer needs to run execute()
 * The method might return true for a variety of reasons, such as a Timer object reaching a count,
 * or based on a switch value.
 */
bool LatchEngage::IsFinished()
{
	return false;
}

/** Called once after isFinished returns true
 * This method is used to clean up variables, if necessary.  Dynamic local variables could be deleted to
 * recover memory.
 */
void LatchEngage::End()
{
	elevator->firstSolClose();
	elevator->secondSolClose();
}

/** Called when another command which requires one or more of the same
 * subsystems is scheduled to run.
 * This method is used if the Subsystem has a requires() statement or if the Command was created
 * by a whileHeld() button action.  When the button is released, the active Command becomes interrupted
 * and canceled.
 */
void LatchEngage::Interrupted()
{
	elevator->firstSolClose();
	elevator->secondSolClose();
}
