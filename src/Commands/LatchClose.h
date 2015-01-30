#ifndef SRC_COMMANDS_LATCHCLOSE_H_
#define SRC_COMMANDS_LATCHCLOSE_H_

#include "../CommandBase.h"
#include "WPILib.h"

class LatchClose: public CommandBase
{
public:
	LatchClose();
	void Initialize(); ///< Runs after the constructor
	void Execute(); ///< This method is called repeatedly
	bool IsFinished(); ///< This method contains the logic of when the command should end
	void End(); ///< The clean-up method when a command ends gracefully (IsFinished returns true)
	void Interrupted(); ///< The clean-up method when a command ends abruptly (from another event, such as a button release)
};

#endif /* SRC_COMMANDS_LATCHCLOSE_H_ */
