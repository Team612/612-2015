#ifndef FORKS_IN_H
#define FORKS_IN_H

#include "../CommandBase.h"
#include "WPILib.h"

 // ForksIn is a command to trigger two Pneumatic Pistons to close thus closing the forks

class ForksIn: public CommandBase
{
public:
	ForksIn(); ///< The constructor for the ForksIn
	void Initialize(); ///< Runs after the constructor
	void Execute(); ///< This method is called repeatedly 
	bool IsFinished(); ///< This method contains the logic of when the command should end
	void End(); ///< The clean-up method when a command ends gracefully (IsFinished returns true)
	void Interrupted(); ///< The clean-up method when a command ends abruptly (from another event, such as a button release)
};

#endif /* FORKS_IN_H */
