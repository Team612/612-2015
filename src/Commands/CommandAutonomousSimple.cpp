#include "CommandAutonomousSimple.h"

/** The constructor of the Command might initialize any class variables pertinent to the Command.
 * Good examples of these variables might be a loop count, a timer.  Variables for robot
 * hardware, such as a motor controller, etc. should not be created here (but in a Subsystem).
 */
CommandAutonomousSimple::CommandAutonomousSimple()
{
	timer = new Timer(); //New timer object
}

/** Called just before this Command runs the first time
 * This is run after the constructor.  The initialization code could be done here, too.
 * In many cases, this method is no different than the constructor, so adding code here
 * is not always necessary.
 */
void CommandAutonomousSimple::Initialize()
{
	timer -> Start(); //Start the timer
}

/** Called repeatedly when this Command is scheduled to run
 * This method is called many times a second and performs the actions of the Command.
 * Setting a motor value by using a Subsystem method call is an example of what would occur
 * in this method.
 *
 */
void CommandAutonomousSimple::Execute()
{
	Talon(1) -> Set(1.0); //Move the robot forward
	Talon(2) -> Set(1.0);
	Talon(3) -> Set(1.0);
	Talon(4) -> Set(1.0);

}

bool CommandAutonomousSimple::IsFinished()
{
	if(timer -> Get() >= 4) //Check to see if timer is at 4 seconds or more
	{
		return true;
	}
	else
	{
		return false;
	}
}

/** Called once after isFinished returns true
 * This method is used to clean up variables, if necessary.  Dynamic local variables could be deleted to 
 * recover memory.
 */
void CommandAutonomousSimple::End()
{
	delete Timer; //Delete timer
}


void CommandAutonomousSimple::Interrupted()
{

}

