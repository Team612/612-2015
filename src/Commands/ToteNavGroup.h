#ifndef LATCH_CPP_SRC_COMMANDS_TOTENAVGROUP_H_
#define LATCH_CPP_SRC_COMMANDS_TOTENAVGROUP_H_

#include "../Subsystems/Drivetrain.h"
#include "CommandBase.h"
#include "WPILib.h"
#include "AutoAlign.h"
#include "MoveToTote.h"

class ToteNavGroup: public CommandGroup
{
public:
	ToteNavGroup();
};

#endif /* LATCH_CPP_SRC_COMMANDS_TOTENAVGROUP_H_ */
