#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Subsystems/Drivetrain.h>
#include <string>
#include "Commands/Command.h"
#include "Subsystems/ExampleSubsystem.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Vision.h"
#include "RobotMap.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	static OI* oi;
	static Elevator* elevator;
	static Drivetrain* drivetrain;
	static Vision* vision;
};

#endif
