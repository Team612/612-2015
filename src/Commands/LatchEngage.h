#ifndef SRC_COMMANDS_LATCHENGAGE_
#define SRC_COMMANDS_LATCHENGAGE_

#include "../CommandBase.h"
#include "WPILib.h"

class LatchEngage: public CommandBase
{
public:
	LatchEngage(bool engaged);
	void Initialize(); ///< Runs after the constructor
	void Execute(); ///< This method is called repeatedly
	bool IsFinished(); ///< This method contains the logic of when the command should end
	void End(); ///< The clean-up method when a command ends gracefully (IsFinished returns true)
	void Interrupted(); ///< The clean-up method when a command ends abruptly (from another event, such as a button release)
private:
	bool engaged;
};

#endif /* SRC_COMMANDS_LATCHENGAGE_ */
