#include "AutonomousSimple.h"

/** The constructor of the Command might initialize any class variables pertinent to the Command.
 * Good examples of these variables might be a loop count, a timer.  Variables for robot
 * hardware, such as a motor controller, etc. should not be created here (but in a Subsystem).
 */
AutonomousSimple::AutonomousSimple(float autoTime, float autoSpeed)
{
	timer = new Timer(); //New timer object
	autotime = autoTime;
	autospeed = autoSpeed;
}

/** Called just before this Command runs the first time
 * This is run after the constructor.  The initialization code could be done here, too.
 * In many cases, this method is no different than the constructor, so adding code here
 * is not always necessary.
 */
void AutonomousSimple::Initialize()
{
	timer->Reset();
	timer->Start(); //Start the timer
}

/** Called repeatedly when this Command is scheduled to run
 * This method is called many times a second and performs the actions of the Command.
 * Setting a motor value by using a Subsystem method call is an example of what would occur
 * in this method.
 *
 */
void AutonomousSimple::Execute()
{
	drivetrain->move(0.0, autospeed, 0.0); //Move the robot forward to score points
}

bool AutonomousSimple::IsFinished()
{
	if(timer->Get() >= autotime) //Check to see if timer is at 4 seconds or more
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
void AutonomousSimple::End()
{
	drivetrain->stop();
	delete timer; //Deletes timer for more memory
}


void AutonomousSimple::Interrupted()
{
	drivetrain->stop();
	delete timer; //Deletes timer for more memory
}
