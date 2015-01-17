#ifndef EXAMPLE_COMMAND_H
#define EXAMPLE_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"

/**
 * ExampleCommand implements a blank command that the robot could execute.
 * This class is used as a template to make other commands.
 *
 * In the command-based robot, the Commands call methods from the Subsystem.
 * While the Subsystem contains all possible robot actions (grouped logically 
 * by related robot components), Commands implement the logic of which 
 * activities the robot should do and the sequential ordering of activities.
 *
 * Commands can run in parallel if they require different Subsystems.  
 * For example, a Command could be active to move the robot, and another 
 * Command active for the payload of the robot, such as an elevator.
 */
class ExampleCommand: public CommandBase
{
public:
	ExampleCommand(); ///< The constructor for the ExampleCommand
	void Initialize(); ///< Runs after the constructor
	void Execute(); ///< This method is called repeatedly 
	bool IsFinished(); ///< This method contains the logic of when the command should end
	void End(); ///< The clean-up method when a command ends gracefully (IsFinished returns true)
	void Interrupted(); ///< The clean-up method when a command ends abruptly (from another event, such as a button release)
};

#endif /* EXAMPLE_COMMAND_H */
