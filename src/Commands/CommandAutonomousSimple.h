#ifndef COMMAND_AUTONOMOUS_SIMPLE_H
#define COMMAND_AUTONOMOUS_SIMPLE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "MecanumDrivetrain.h"


class CommandAutonomousSimple: public CommandBase
{
public:
	CommandAutonomousSimple(); ///< The constructor for the ExampleCommand
	void Initialize(); ///< Runs after the constructor
	void Execute(); ///< This method is called repeatedly 
	bool IsFinished(); ///< This method contains the logic of when the command should end
	void End(); ///< The clean-up method when a command ends gracefully (IsFinished returns true)
	void Interrupted(); ///< The clean-up method when a command ends abruptly (from another event, such as a button release)
private:
	Timer* timer; //New timer object
};

#endif /* COMMAND_AUTONOMOUS_SIMPLE_H */
