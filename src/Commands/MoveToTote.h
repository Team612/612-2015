#ifndef MOVETOTOTE_H_
#define MOVETOTOTE_H_

#include "../CommandBase.h"
#include "WPILib.h"

class MoveToTote: public CommandBase
{
public:
	MoveToTote();
	void Initialize(); ///< Runs after the constructor
	void Execute(); ///< This method is called repeatedly
	bool IsFinished(); ///< This method contains the logic of when the command should end
	void End(); ///< The clean-up method when a command ends gracefully (IsFinished returns true)
	void Interrupted(); ///< The clean-up method when a command ends abruptly (from another event, such as a button release)
};

#endif /* LATCH_CPP_SRC_COMMANDS_MOVETOTOTE_H_ */
