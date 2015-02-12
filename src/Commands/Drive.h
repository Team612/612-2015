#ifndef DRIVE_H
#define DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include <Timer.h>
#include "RobotMap.h"

class Drive: public CommandBase
{
public:
	Drive(Joystick* stick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Joystick* joy;

};

#endif
