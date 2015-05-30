#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Subsystems/Drivetrain.h>
#include <string>
#include "Commands/Command.h"
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
	/// Creates a new command base.
	/// A commandbase is series of commands to be executed one after another
	/// @param name (char) A name for the command base
	CommandBase(char const *name);
	CommandBase(); ///< CommandBase constructor
	static void init(); ///< initializes command base
	static OI* oi; ///< OI object
	static Elevator* elevator; ///< elevator object
	static Drivetrain* drivetrain; ///< drivetrain object
	static Vision* vision; ///< vision object
};

#endif
