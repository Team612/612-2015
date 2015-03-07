#ifndef FORKS_OUT_H
#define FORKS_OUT_H

#include "../CommandBase.h"
#include "WPILib.h"

 // ForksOut is a command to trigger two Pneumatic Pistons to open thus closing the forks.

class ForksOut: public CommandBase
{
public:
	ForksOut(); ///< The constructor for the ForksOut
	void Initialize(); ///< Runs after the constructor
	void Execute(); ///< This method is called repeatedly 
	bool IsFinished(); ///< This method contains the logic of when the command should end
	void End(); ///< The clean-up method when a command ends gracefully (IsFinished returns true)
	void Interrupted(); ///< The clean-up method when a command ends abruptly (from another event, such as a button release)
};

#endif /* FORKS_OUT_H */
