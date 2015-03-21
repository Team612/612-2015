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
	Drive(float x, float y, float rotation);
	Drive(GamePad* joystick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	enum DriveMode {MANUAL, JOYSTICK};

	DriveMode mode;
	float targetX;
	float targetY;
	float targetRotation;
	int feedState;
	bool isPressed;
	bool wasPressed;
	//CANTalon* leftFeedWheel;
	//CANTalon* rightFeedWheel;

	GamePad* joyObj;
};

#endif
