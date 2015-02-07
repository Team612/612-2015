// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include <Commands/Rumble.h>
#include "CommandBase.h"
#include "RobotMap.h"

Rumble::Rumble()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(haptic);
	Requires(networktables)
	this->counter = 0;
}

Rumble::~Rumble()
{
	delete this->counter;
}

// Called just before this Command runs the first time
void Rumble::Initialize()
{
	this->counter = 0;
}

// Called repeatedly when this Command is scheduled to run
void Rumble::Execute()
{
	// Prevents duplicate rumble signals from being sent to the controller
	if(this->counter == 0)
	{
		this->counter++;
		this->StartRumble(DEFAULT_RUMBLE_DURATION);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Rumble::IsFinished() {
	return (this->counter > 0);
}

// Called once after isFinished returns true
void Rumble::End()
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Rumble::Interrupted() {

}

// Starts the rumble
void Rumble::StartRumble(float duration)
{
	// Send signal to controller over NetworkTables as seen in last year's code
}