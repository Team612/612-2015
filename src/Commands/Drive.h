#ifndef DRIVE_H
#define DRIVE_H

#include "CommandBase.h"
#include "WPILib.h"
#include <Timer.h>
#include "RobotMap.h"
#include "Subsystems/Drivetrain.h"
#include <CANTalon.h>
#include "GamePad.h"

class Drive: public CommandBase
{
public:
	///Constructor autonomous
	///@param x distance to go left-right
	///@param y distance to go foward-back
	///@param rotation angle to rotate to
	Drive(float x, float y, float rotation);
	///Constructor with joystick
	///@joystick joystick object to use
	Drive(GamePad* joystick);
	void Initialize(); ///<Sets up all the variables
	void Execute(); ///<Calculates distance traveled with talons and moves robot
	bool IsFinished(); ///<returns false
	void End(); ///<stops robot
	void Interrupted(); ///<stops robot
private:
	enum DriveMode {MANUAL, JOYSTICK}; ///<Possible modes for drive command

	DriveMode mode;
	float targetX;
	float targetY;
	float targetRotation;
	//CANTalon* leftFeedWheel;
	//CANTalon* rightFeedWheel;

	GamePad* joyObj;
};

#endif
