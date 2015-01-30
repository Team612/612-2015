#ifndef Move_H
#define Move_H

#include "../CommandBase.h"
#include "WPILib.h"
#include <Joystick.h>
#include "RobotMap.h"
#include "Robot.h"

class Move: public CommandBase
{
public:
	Move(Robot* r, Joystick* j);
	~Move();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Robot* robot;
	Joystick* joystick;
};

#endif
